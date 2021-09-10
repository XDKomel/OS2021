#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void ex1() {
    if (fork() == 0) {
        printf("Hello from child [");
        printf("%d", getpid());
        printf(" - n]\n");
    } else {
        printf("Hello from parent [");
        printf("%d", getpid());
        printf(" - n]\n");
    }
}

int main() {
    ex1();
    return 0;
}
