#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubbleSort(int n, int array[n]) {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (array[j] < array[i]) {
                swap(&array[i], &array[j]);
            }
        }
    }
}

void printArray(int n, int array[n]) {
    for (int i = 0; i < n; i++) {
        printf("%d", array[i]);
        printf("\n");
    }
}

int main(){

    int array[10] = { 99, 2, 50, 4, 5, 6, 7, 8, 9, 10 };
    bubbleSort(10, array);
    printArray(10, array);
    return 0;
}