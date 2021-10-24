#include "stdlib.h"
#include <dirent.h>
#include <printf.h>
#include <sys/stat.h>
#include <string.h>

char* file_path(char* dir, char* filename) {
    char* dest = malloc(255 * sizeof(char));
    strcpy(dest, dir);
    strcat(dest, "/");
    strcat(dest, filename);
    return dest;
}


int main() {
    char *dir_address = "../../../week10/ex4/tmp";
    DIR *dir = opendir(dir_address);
    struct dirent *entry;
    while((entry = readdir(dir)) != NULL) {
        if(entry->d_name[0] == '.') {
            continue;
        }
        struct stat stats;
        stat(file_path(dir_address, entry->d_name), &stats);
        if(stats.st_nlink >= 2) {
            __darwin_ino64_t ino = stats.st_ino;
            char* name = entry->d_name;
            DIR *dir_copy = opendir(dir_address);
            printf("%s - ", entry->d_name);
            while((entry = readdir(dir_copy)) != NULL) {
                stat(file_path(dir_address, entry->d_name), &stats);
                if(stats.st_ino == ino && strcmp(entry->d_name, name)) {
                    printf("%s, ", entry->d_name);
                }
            }
            printf("\n");
        }
    }

    return 0;
}