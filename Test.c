#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 100001

// int a[maxlen], n;

// void swap(int* a, int* b){
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// int heapify(int i, int a[], int n){
//     int largest = i, left = 2*i+1, right = 2*i+2;
//     if(left < n && a[largest] < a[left]) largest = left;
//     if(right < n && a[largest] < a[right]) largest = right;
//     if(i != largest){
//         swap(&a[i], &a[largest]);
//         heapify(largest, a, n);
//     }
// }

// void input(){
//     scanf("%d", &n);
//     for(int i=0; i<n; i++) scanf("%d", &a[i]);
// }

// int main(){
//     input();
//     for(int i=n/2-1; i>=0; i--) heapify(i, a, n);
//     for(int i=0; i<n; i++) printf("%d ", a[i]);
//     return 0;
// }

void dequy2(int n, int p){
    if (n <= 0){
        return;
    }
    
    int k = (n + p) % 2;
    
    if(k == 0){
        printf("%d ", n % 2);
        n = n / 10;
        dequy2(n, p);
    }
    else {
        printf("%d ", n % 2);
        n = n / 10 * p;
        dequy2(n, p);
    }
    
    printf("%d ", n);
}

int main(){
    dequy2(202417009,5);
}