/*Given a dataset about orders raised over the time, each item is under the format:
                                        <OrderID> <TimePoint>
in which the order <OrderID> (<OrderID> is a string of length from 2 to 15) is raised at time point <TimePoint> (the <TimePoint> is a string of length 8 representing the time point hh:mm:ss, for example, 08:30:14 means 8 hour 30 minutes 14 seconds)
Perform a sequence of queries about the given dataset of 3 categories:
?number_orders: return the number of orders raised 
?number_orders_in_period <FromTimePoint> <ToTimePoint>: return the number of orders raised in the period from time point <FromTimePoint> to time point <ToTimePoint>
?number_orders_at_time <TimePoint>: return the number of orders raised at the time point <TimePoint>

Input
The first block is a sequence of lines (number of lines can be up to 100000), each line contains an information about an order raised with the format above. The first block is terminated with a line containsing the character #
The second line is a sequence of lines (number of lines can be up to 100000), each line contains a query described above. The second line is terminated with a line containing ###

Output
Write in each line, the result of the correspinding query.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 100000

typedef struct inf{
    char oderid[16];
    char time[9];
} inf;

int cmp(const void* ptr1, const void* ptr2){
    inf* x = (inf*)ptr1;
    inf* y = (inf*)ptr2;
    return strcmp(x->time, y->time);
}

int lower(inf*a, int n, const char* key){
    int l = 0, r = n-1;
    while(l<=r){
        int m = (l+r)/2;
        if(strcmp(a[m].time, key) < 0) l = m + 1;
        else r = m - 1;
    }
    return l;
}

int upper(inf*a, int n, const char* key){
    int l = 0, r = n-1;
    while(l<=r){
        int m = (l+r)/2;
        if(strcmp(a[m].time, key) <= 0) l = m + 1;
        else r = m - 1;
    }
    return l;
}

int main(){
    inf* a = (inf*)malloc(maxlen*sizeof(inf));
    int n = 0, found = 0;
    char c[50];
    while(1){
        if(!fgets(c, sizeof(c), stdin)) break;
        c[strcspn(c, "\n\r")] = '\0';
        if(strcmp(c, "#") == 0) break;
        sscanf(c, "%s %s", a[n].oderid, a[n].time);
        n++;
    }
    while(1){
        if(!fgets(c, sizeof(c), stdin)) break;
        c[strcspn(c, "\n\r")] = '\0';
        if(strcmp(c, "###") == 0) break;
        else if(strcmp(c, "?number_orders") == 0) printf("%d\n", n);
        else if(strncmp(c, "?number_orders_in_period ", 25) == 0){
            char start[9];
            char end[9];
            sscanf(c + 25, "%s %s", start, end);
            if(!found){
                qsort(a, n, sizeof(inf), cmp);
                found = 1;
            }                 
            printf("%d\n", upper(a, n, end) - lower(a, n, start));
        }
        else if(strncmp(c, "?number_orders_at_time ", 23) == 0){
            char timepoint[9];
            sscanf(c + 23, "%s", timepoint);
             if(!found){
                qsort(a, n, sizeof(inf), cmp);
                found = 1;
            }                 
            printf("%d\n", upper(a, n, timepoint) - lower(a, n, timepoint));
        }
    }
}