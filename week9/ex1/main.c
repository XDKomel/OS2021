#include "stdlib.h"
#include <printf.h>
#include <unistd.h>
#include <stdint.h>

struct Page {
    uint16_t bit;
    int id;
};

int main() {
    FILE *file = fopen("../input.txt", "r");
    int n;
    scanf("%d", &n);
    struct Page *frames = malloc(sizeof(struct Page) * n);
    for(int i = 0; i < n; i++) {
        frames[i].id = -1;

    }
    int *pages = malloc(sizeof(int) * 1000);
    for(int i = 0; i < 1000; i++) {
        fscanf(file, "%d ", &pages[i]);
    }
    int hits = 0;
    int miss = 0;
    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < n; j++) {
            frames[j].bit = (frames[j].bit >> 1);
        }
        printf("current page number is %d\n", pages[i]);
        uint16_t min = INT16_MAX;
        int to_be_written_position = -1;
        int equal_pages_position = -1;
        for(int j = n-1; j >= 0; j--) {
            if(frames[j].bit < min) {
                min = frames[j].bit;
                to_be_written_position = j;
            }
            if(frames[j].id == pages[i]) {
                equal_pages_position = j;
            }
        }
        int minimal_negative_page = INT16_MAX;
        int minimal_negative_page_position = -1;
        for(int j = n-1; j >= 0; j--) {
            if(frames[j].id == -1 && frames[j].bit < minimal_negative_page) {
                minimal_negative_page = frames[j].bit;
                minimal_negative_page_position = j;
            }
        }
        if(minimal_negative_page_position != -1) {
            to_be_written_position = minimal_negative_page_position;
        }
        if(equal_pages_position != -1) {
            to_be_written_position = equal_pages_position;
            hits++;
        } else {
            miss++;
        }
        frames[to_be_written_position].bit = INT16_MAX+1;
        frames[to_be_written_position].id = pages[i];
        for(int j = 0; j < n; j++) {
            printf("i = %d id = %d %d\n", j, frames[j].id, frames[j].bit);
        }
        printf("\n\n");
    }

    printf("hits = %d    miss = %d    ratio = %f\n", hits, miss, (float)hits/(float)miss);

    return 0;
}