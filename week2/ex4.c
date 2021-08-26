#include <stdio.h>

void swap(int *one, int *two) {
    int temp = *one;
    *one = *two;
    *two = temp;
}

int main() {

    char a[256];
    char b[256];
    fgets(a, 256, stdin);
    fgets(b, 256, stdin);

    int temp1 = 0;
    int temp2 = 0;

    sscanf(a, "%d", &temp1);
    sscanf(b, "%d", &temp2);

    int *one = &temp1;
    int *two = &temp2;

    swap(one, two);

    printf("%d", *one);
    printf("\n");
    printf("%d", *two);

    return 0;
}
