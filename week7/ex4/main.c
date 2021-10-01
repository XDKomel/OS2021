#include <libc.h>
#include <stdio.h>
#include <stdlib.h>

void* __realloc__(void* ptr, size_t size) {
    void *real = malloc(size);
    memset(real, 0, size);
    if(ptr != NULL)
        memcpy(real, ptr, size);
    free(ptr);
    return real;
}

int main(){

    int initial_size = 10;
    int new_size = 30;
    int* ptr = malloc(sizeof(int)*initial_size);
    for(int i = 0; i < initial_size; i++) {
        ptr[i] = 100;
    }
    ptr = __realloc__(new_size, sizeof(int)*new_size);
    for(int i = 0; i < new_size; i++) {
        printf("%d ", ptr[i]);
    }

    return 0;
}
