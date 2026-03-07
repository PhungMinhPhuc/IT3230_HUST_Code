/*Job Selection & Planning
Given n jobs J = {1,. . .,n}. Each job i has a deadline d(i) and associated profit p(i) if the job is finished before the deadline. Every job takes the single unit of time, so the minimum possible deadline for any job is 1. It is also noted that no more than one job can be executed at a time.
Select and schedule a subset of jobs of J such that the total profits is maximal.
Input
Line 1: contains a positive integer n (1 <= n <= 10^5)
Line i+1 (i=1,. . . ,n) contains d(i) and p(i) (1 <= d(i), p(i) <= 10^5)
Output
Write to total profits obtained from the subset of jobs found.

Example
Input
6
3 10
2 40
6 70
3 50
5 80
1 60
Output
300*/

//Cách 1: Backtracking
// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// #include <stdlib.h>

// #define maxlen 100000

// int n, max = 0, f = 0;
// int d[maxlen], p[maxlen], x[maxlen][2], visited[maxlen] = {0};

// void printsol(){
//     for(int i=1; i<=n; i++){
//         printf("%d %d\n", x[i][0], x[i][1]);
//     }
// }

// void try(int k){
//     if(k == n){
//         if(f > max) max = f;
//         return;
//         //printsol();
//     }
//     for(int i=0; i<n; i++){
//         if(!visited[i]){
//             // x[k][0] = d[i];
//             // x[k][1] = p[i];
//             visited[i] = 1;
//             if(d[i] >= k){
//                 f += p[i];
//                 try(k+1);
//                 f-=p[i]; 
//             }
//             try(k+1);
//             visited[i] = 0;
//         }
//     }
// }
//
// int main(){
//     scanf("%d", &n);
//     for(int i=0; i<n; i++) scanf("%d %d", &d[i], &p[i]);
//     try(1);
//     printf("%d", max);
// }

//Cách 2: Thuật toán tham lam
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 10000

typedef struct job{
    int d;
    int p;
} job;

int cmp(void const* ptr1, void const* ptr2){
    job* x = (job*)ptr1;
    job* y = (job*)ptr2;
    return y->p - x->p;
}

int main(){
    int n, sum = 0, slot[maxlen] = {0};
    scanf("%d", &n);
    job a[n];
    for(int i=0; i<n; i++) scanf("%d %d", &a[i].d, &a[i].p);
    qsort(a, n, sizeof(job), cmp);
    //for(int i=0; i<n; i++) printf("%d %d\n", a[i].d, a[i].p);
    for(int i=0; i<n; i++){
        for(int j=a[i].d; j>=1; j--){
            if(!slot[j]){
                slot[j] = 1;
                sum += a[i].p;
                break;
            }
        }
    }
    printf("%d", sum);
}