#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void line() {
    printf("\n");
}

void* printId(void* args) {
    printf("%d", pthread_self());
    line();
    return NULL;
}

int main() {
    int n;
    scanf("%d", &n);

    pthread_t thread;
    for(int i = 0; i < n; i++) {
        printf("creating a thread number %d", i+1);
        printf(": ");
        pthread_create(&thread, NULL, printId, NULL);
        pthread_join(thread, NULL);
    }
    return 0;
}
