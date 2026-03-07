/*Given a sequence of n vectors A[1], A[2], ..., A[n] of length m. Sort these vector in a non-decreasing order.
Input
Line 1 contains 2 positive integers n and m (1 <= n <= 100000, 1 <= m <= 10)
Line i+1 (i = 1, 2, ..., n): contains m integers which are items of vector A[i] (items are vary from 1 to 100)

Output
Line i (i = 1, 2, ..., n): write the items of vector A[i] after sorting (after each item, there is a SPACE character)

Example
Input 
6 3
10 9 7 
5 10 2 
10 9 1 
4 7 3 
7 5 10 
7 9 3

Output 
4 7 3
5 10 2
7 5 10
7 9 3
10 9 1
10 9 7*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 1000

int n, m;

int cmp(void const* ptr1, void const* ptr2) {
    const int* x = (const int*)ptr1;
    const int* y = (const int*)ptr2;
    for (int j = 0; j < m; j++) { // So sánh từ cột 0 đến m-1
        if (x[j] < y[j]) return -1;
        if (x[j] > y[j]) return 1;
    }
    return 0;
}

int main(){
    scanf("%d %d", &n, &m);
    int c[n][m];
    getchar();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &c[i][j]);
        }
    }
    qsort(c, n, sizeof(c[0]), cmp);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    } 
}