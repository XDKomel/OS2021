#include <float.h>
#include <limits.h>
#include <stdio.h>
int main() {

    int intMax = INT_MAX;
    float floatMax = FLT_MAX;
    double doubleMax = DBL_MAX;

    printf("maximum int is ");
    printf("%d", intMax);
    printf("\nmaximum float is ");
    printf("%f", floatMax);
    printf("\nmaximum double is ");
    printf("%f", doubleMax);


    return 0;
}
