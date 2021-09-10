#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


char** str_split(char* a_str, const char a_delim, int* numberOfArgs)
{
    char **result;
    size_t count = 0;
    char *tmp = a_str;
    char *last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    while(*tmp) {
        if(a_delim == *tmp) {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    count += last_comma < (a_str + strlen(a_str) - 1);
    count++;

    result = malloc(sizeof(char*) * count);

    if(result) {
        size_t idx = 0;
        char *token = strtok(a_str, delim);

        while(token) {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }
    *numberOfArgs = (int) count-1;
    return result;
}


void dropLineBreaks(char text[]) {
    for(int i = 0; i < 255; i++) {
        if(text[i] == '\n') {
            text[i] = '\0';
        }
    }
}

void copyArray(char *base, char *copy, int size) {
    for(int i = 0; i < size; i++) {
        copy[i] = base[i];
    }
}

int sizeOf(char text[]) {
    int size = 0;
    while(text[size] != '\n') {
        size++;
    }
    return ++size;
}

void addPath(char text[]) {
    char *path = "/bin/";
    int size = sizeOf(text);
    char copy[size];

    copyArray(text, copy, size);

    for(int i = 0; i < 5; i++) {
        text[i] = path[i];
    }
    for(int i = 5; i < 255; i++) {
        text[i] = copy[i-5];
        if(copy[i-5] == '\n')
            return;
    }
}

int main() {
    char command[255];
    fgets(command, 255, stdin);

    if(command[0] != '/') {
        addPath(command);
    }
    dropLineBreaks(command);

    int numberOfArgs = 0;
    char **args = str_split(command, ' ', &numberOfArgs);

    execve(args[0], args, NULL);

    return 0;
}
