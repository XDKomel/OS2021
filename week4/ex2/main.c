#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void ex2() {
    for(int i = 0; i < 3; i++) {
        fork();
        sleep(5);
    }
}

int main() {
    ex2();
    return 0;
}
