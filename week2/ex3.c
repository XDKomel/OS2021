#include <stdio.h>
int main() {

    int n;
    char nAsString[256];
    fgets(nAsString, 256, stdin);
    sscanf(nAsString, "%d", &n);

    for(int i = 1; i <= n; i++) {
        for(int k = 0; k < n-i; k++) {
            printf(" ");
        }
        for(int k = 0; k < 2*i-1; k++) {
            printf("*");
        }
        for(int k = 0; k < n-i; k++) {
            printf(" ");
        }
        printf("\n");
    }



    return 0;
}
