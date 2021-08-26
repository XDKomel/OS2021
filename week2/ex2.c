#include <stdio.h>
#include <string.h>

int main() {

    char word[256];
    printf("enter a string\n");
    fgets(word, 256, stdin);
    long n = strlen(word);

    for(int i = n-1; i >= 0; i--) {
        printf("%c", word[i]);
    }

    return 0;
}
