/*Given a sequence of integers a1, a2, ..., an. Sort the sequence in a non-deccreasing order.
Input
Line 1: contains an integer n (1 <= n <= 1000000)
Line 2: a1, a2, ..., an. (0 <= ai <= 100000)
Output
Write the sorted sequence, elements are separated by a SPACE chharacter.
Example
Input
4
1 3 4 2
Output
1 2 3 4*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 1000000

int cmp(void const* ptr1, void const* ptr2){
    int* x = (int*)ptr1;
    int* y = (int*)ptr2;
    return *x - *y;
}

int main(){
    int n, a[maxlen];
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    for(int i=0; i<n; i++) printf("%d ", a[i]);
}