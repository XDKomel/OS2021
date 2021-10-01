#include <libc.h>
#include <stdio.h>
#include <stdlib.h>

//void* __realloc__(void* ptr, size_t size) {
//    void *real = malloc(size);
//    memset(real, 0, size);
//    if(ptr != NULL)
//        memcpy(real, ptr, size);
//    free(ptr);
//    return real;
//}

int main(){

    char foo[] = "Hello World";
    char **s = malloc(sizeof(char) * sizeof(foo));
    *s = foo;
    printf("s is %s\n",s);
    s[0] = foo;
    printf("s[0] is %s\n",s[0]);

    return 0;
}
