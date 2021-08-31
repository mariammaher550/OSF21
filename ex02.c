#include <string.h>
#include "stdio.h"
int N = 1e5+5;
int main()
{
    char str[N] ;
    char c;
    int idx = 0;
    printf("Please enter a string: \n");
//    while(scanf("%c", &c)){
//        str[idx] = c;
//        idx++;
//    }
    scanf("%s", str);
    printf("Here is the inverted string:\n");
    for(int i = strlen(str) - 1; i >= 0; i-- )
        printf("%c", str[i]);
}