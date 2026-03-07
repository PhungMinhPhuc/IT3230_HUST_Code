/*Pair sum
Given a sequence of positive integer number a1... an. Given a query integer x, calculate the number of pair (ai, aj) so that ai + aj <= x.
Input: 
Line 1: n
Line 2: n positive integer number a1...an
Line 3: Number of queries q
Next q line, each contains a query x
Output: q line, each contains the number of pair satisfied a query
Example
Input:
5
5 10 2 7 9
2
15
13
Output:
7
5*/

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
    int n, q;
    scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp);
    // for(int i=0; i<n; i++) printf("%d ", a[i]);
    scanf("%d", &q);
    for(int i=1; i<=q; i++){
        int x, left = 0, right = n-1, count = 0;
        scanf("%d", &x);
        while(left < right){
            if(a[left] + a[right] <= x){
                count += right - left;
                left++;
            }
            else right--;
        }
        printf("%d\n", count);
    }
}