#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main() {
    DIR *dir;
    struct dirent *ep;
    dir = opendir("./");

    if(dir != NULL) {
        while(ep = readdir(dir)) {
            puts(ep->d_name);
        }
        closedir(dir);
    } else {
        perror("Couldn't open the directory");
    }
    return 0;
}