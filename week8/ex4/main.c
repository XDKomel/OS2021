#include "stdlib.h"
#include <printf.h>
#include <unistd.h>

int main() {
    char *data;
    int bytes = (1024*1024*10);
    data = (char *) malloc(bytes);
    for (int j = 0; j < 10; ++j) {
        for (int i = 0; i < bytes; ++i) {
            data[i] = '0';
        }
        sleep(1);
        struct rusage usage;
        getrusage(RUSAGE_SELF, &usage);
        printf("%ld\n", usage.ru_maxrss);
    }
    return 0;
}