#include <stdio.h>
#include <limits.h>
#include <float.h>
int main() {
   int a;
   float b;
   double c;
   a = INT_MAX;
   b = FLT_MAX;
   c = DBL_MAX;
    printf("The maximum value of Int is : %d\n The size : %lu\n", a , sizeof(a) );
    printf("The maximum value of Int is : %f\n The size : %lu\n", b,sizeof(b) );
    printf("The maximum value of Int is : %lf\n The size : %lu\n", c , sizeof(c) );
    return 0;
}
