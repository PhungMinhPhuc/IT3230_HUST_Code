/*Given 2 sets of integers A = {a1, a2, . . ., an} and B = {b1, b2, . . ., bn}. Find the common subset of A and B having highest cardinality.
Input
Line 1 contains 2 positive integers n and m (1 <= n,m <= 100000)
Line 2: contains n positive integers a1, a2, . . ., an (1 <= ai <= 1000000)
Line 3: contains m positive integers b1, b2, . . ., bm (1 <= ai <= 1000000)

Output
Write the cardinalnity of the subset found.

Example
Input
6 6
7 3 10 1 2 8 
6 2 8 10 5 7 

Output 
4

Explanation. The max-cardinality common subset of A and B is {2, 8, 10, 7}*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 1000

int cmp(void const* ptr1, void const* ptr2){
    int* x = (int*)ptr1;
    int* y = (int*)ptr2;
    return *x - *y;
}

int main(){
    int n, m, count = 0;
    scanf("%d %d", &n, &m);
    int a[n], b[m];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<m; i++) scanf("%d", &b[i]);
    qsort(a, n, sizeof(int), cmp);
    qsort(b, m, sizeof(int), cmp);
    int index1 = 0, index2 = 0;
    while(index1 < n && index2 < n){
        if(a[index1] == b[index2]){
            count++;
            index1++;
            index2++;
        }
        else if(a[index1] < b[index2]) index1++;
        else index2++;
    }
    printf("%d", count);
}