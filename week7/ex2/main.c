#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Enter the number of elements:\n");
    int n;
    scanf("%d", &n);

    int *array = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) {
        array[i] = i;
        printf("%d\n", array[i]);
    }
    free(array);


    return 0;
}
