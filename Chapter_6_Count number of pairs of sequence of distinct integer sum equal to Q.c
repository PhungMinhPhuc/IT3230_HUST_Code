/*Given a sequence of distinct integers a1, a2, …, an and an integer Q. Count number M of pairs (i, j) such that 1 ≤ i< j ≤ n and ai + aj= Q
Input
•Line 1: contains two integers n and Q (1 <= n, Q<= 10^6)
•Line 2: contains a1, a2, …, an
Ouput
•Write the value of M
Example
Input
5 8
4 6 5 3 2
Output
2*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 1000000

int a[maxlen];

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int a[], int i, int n){
    int l = 2*i, r = 2*i+1, largest = i;
    if(l < n && a[l] > a[largest]) largest = l;
    if(r < n && a[r] > a[largest]) largest = r;
    if(largest != i){
        swap(&a[i], &a[largest]);
        heapify(a, largest, n);
    }
}

void heapsort(int a[], int n){
    for(int i=n/2-1; i>=0; i--) heapify(a, i, n);
    for(int i=n-1; i>0; i--){
        swap(&a[0], &a[i]);
        heapify(a, 0, i);
    }
}

int binarysearch(int a[], int start, int end, int key){
    int l = start, r = end;
    while(l<=r){
        int m = (l+r)/2;
        if(key > a[m]) l = m+1;
        else if(key < a[m]) r = m-1;
        else return 1;
    }
    return 0;
}

int main(){
    int n, q, count = 0;
    scanf("%d %d", &n, &q);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    heapsort(a, n);
    for(int i=0; i<n; i++) {
        if(binarysearch(a, i+1, n-1, q-a[i])) count ++;
    }
    printf("%d", count);
}