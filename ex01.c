#include <stdio.h>
#include <unistd.h>
#include <malloc.h>
#include <memory.h>
#include <sys/resource.h>
#include <stdbool.h>



int main(){
    FILE *in_file  = fopen("input.txt", "r");
    bool pageIsInFrame[10005] = {}; // indicates if ths memory in frame or not
    int r_bit[10005] = {};
    int pageCounter[10005] = {};

    int n , m , currentClockCycle = 1, x, hit = 0, pagesInFrame = 0, miss = 0;
    fscanf(in_file,"%d %d", &n, &m);
    while(m--)
    {
        fscanf(in_file,"%d", &x);
        if(currentClockCycle == x )
        {
            fscanf(in_file,"%d", &x);
            if(pageIsInFrame[x]) {
                //  printf("page number %d  on clockCycle %d is in the Frame !\n", x, currentClockCycle);
                hit++;
                printf("1\n");
                r_bit[x] = 1;
            }
            else{
                miss++;
                printf("0\n");
                if(pagesInFrame < n)
                {
                    pagesInFrame ++;
                    r_bit[x] = 1;
                    pageIsInFrame[x] = true;
                    // pageCounter[x] = (pageCounter[x] >> 1) | (r_bit[x] << 7);
                }
                else{
                    //remove the oldest page aka the page with the smallest counter
                    int sm = 2e31;
                    int pageToRemove;
                    for(int i = 0 ; i < 10005; i++)
                        if (pageCounter[i] < sm && pageIsInFrame[i] )
                        {
                            sm = pageCounter[i] ;
                            pageToRemove = i;
                        }
                    //   printf("PAGE TO REMOVE: %d with counter %d\n", pageToRemove, pageCounter[pageToRemove]);
                    pageIsInFrame[pageToRemove] = false;
                    r_bit[pageToRemove] = 0;
                    pageCounter[pageToRemove] = 0;
                    // add current page
                    r_bit[x] = 1;
                    pageIsInFrame[x] = true;
                }
            }
        }
        else{
            currentClockCycle = x;
            for(int i = 0; i < 10005; i++)
                pageCounter[i] = (pageCounter[i] >> 1) | (r_bit[i] << 7);
            memset(r_bit, 0, 10005);
            fscanf(in_file,"%d", &x);
            if(pageIsInFrame[x]){
                //   printf("page number %d  on clockCycle %d is in the Frame !\n", x, currentClockCycle);
                hit++;
                printf("1\n");
                r_bit[x] = 1;
            }
            else {
                miss++;
                printf("0\n");
                if (pagesInFrame < n) {
                    pagesInFrame++;
                    r_bit[x] = 1;
                    pageIsInFrame[x] = 1;
                } else {
                    //remove the oldest page aka the page with the smallest counter
                    int sm = 2e31;
                     int pageToRemove;
                    for (int i = 1; i < 10005; i++)
                        if (pageCounter[i] < sm && pageIsInFrame[i]) {
                            sm = pageCounter[i];
                            pageToRemove = i;
                        }
                    //  printf("PAGE TO REMOVE: %d with counter %d\n", pageToRemove, pageCounter[pageToRemove]);
                    pageIsInFrame[pageToRemove] = false;
                    r_bit[pageToRemove] = 0;
                    pageCounter[pageToRemove] = 0;
                    //add current page to frame
                    r_bit[x] = 1;
                    pageIsInFrame[x] = true;

                }

            }
        }
    }
    printf("%f", (double ) hit/ miss);
}
