#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) {
    char *command[255];
    fgets((char *) command, sizeof(command), stdin);
    system((const char *) command);
    return 0;
}
