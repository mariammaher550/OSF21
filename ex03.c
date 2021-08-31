#include <string.h>
#include "stdio.h"
int main(int argc, char *argv[])
{
   int n, sps;
   sscanf(argv[1], "%d", &n);

       for(int stars = 1; stars < 2*n ; stars += 2)
       {
           sps = 2*n - stars;
           sps /= 2;
           for(int j = 0; j < sps; j++)
               printf(" ");
           for(int j = 0; j < stars; j++)
               printf("*");
           printf("\n");
       }

}