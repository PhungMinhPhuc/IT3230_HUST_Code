/*Given a sequence of strings S1, S2, . . ., Sn. Sort the given sequence in non-decreasing order.

Input
Line 1: contains a positive integer n (1 <= n <= 100000)
Line i+1 (i = 1, 2, ..., n): contains Si

Output
Write in each line a string in the sorted sequence 

Example
Input 
10
O0001
Z002
R003
R00004
P05
P00006
T0007
X08
N09
I010

Output 
I010
N09
O0001
P00006
P05
R00004
R003
T0007
X08
Z002*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 100000

typedef struct string{
    char c[100];
} string;

int cmp(void const* ptr1, void const* ptr2){
    string* x = (string*)ptr1;
    string* y = (string*)ptr2;
    return strcmp(x->c, y->c);
}

int main(){
    int n;
    string a[maxlen];
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%s", a[i].c);
    qsort(a, n, sizeof(string), cmp);
    for(int i=0; i<n; i++) printf("%s\n", a[i].c);
}