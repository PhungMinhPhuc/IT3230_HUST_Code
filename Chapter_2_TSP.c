/*Bài 1: Liệt kê tất cả và tính tổng mỗi đường đi*/
// #include <stdio.h>
// #include <stdlib.h>

// #define maxlen 1000

// int visited[maxlen] = {0};
// int x[maxlen]; //Chứa các kết quả thăm thành phố
// int n, f = 0, start;
// int **a;

// void input(){  
//     scanf("%d", &n);
//     a = (int**)malloc(n*sizeof(int*));
//     for(int i=0; i<n; i++) a[i] = (int*)malloc(n*sizeof(int)); 
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             scanf("%d", &a[i][j]);
//         }
//     }
// }

// void output(){
//     if(a[x[n-1]][start] > 0){
//         for(int i=0; i<n; i++) printf("%d->", x[i]+1);
//         printf("%d - Total: %d\n", start+1, f + a[x[n-1]][start]);
//     }
// }

// void travel(int k){
//     for(int i=0; i<n; i++){
//         if(!visited[i] && a[x[k-1]][i] > 0){
//             x[k] = i;
//             visited[i] = 1;
//             f += a[x[k-1]][i];
//             if(k == n-1) output();
//             else travel(k+1);
//             visited[i] = 0;
//             f -= a[x[k-1]][i];
//         }
//     }
// }

// int main(){
//     input();
//     scanf("%d", &start);
//     start = start -1;
//     x[0] = start;
//     visited[start] = 1;
//     travel(1);
// }

/*Bài 2: Đếm số đường đi có chi phí nhỏ hơn hoặc bằng m*/
// #include <stdio.h>
// #include <stdlib.h>

// #define maxlen 1000

// int visited[maxlen] = {0};
// int x[maxlen]; //Chứa các kết quả thăm thành phố
// int n, m, f = 0, count = 0, start = 1-1;
// int **a;

// void input(){  
//     scanf("%d %d", &n, &m);
//     a = (int**)malloc(n*sizeof(int*));
//     for(int i=0; i<n; i++) a[i] = (int*)malloc(n*sizeof(int)); 
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             scanf("%d", &a[i][j]);
//         }
//     }
// }

// void output(){
//     if(a[x[n-1]][start] > 0){
//         printf("%d\n", count);
//     }
// }

// void travel(int k){
//     for(int i=0; i<n; i++){
//         if(!visited[i] && a[x[k-1]][i] > 0){
//             x[k] = i;
//             visited[i] = 1;
//             f += a[x[k-1]][i];
//             if((k == n-1) && (f + a[x[n-1]][start] <= m)) count ++;
//             else travel(k+1);
//             visited[i] = 0;
//             f -= a[x[k-1]][i];
//         }
//     }
// }

// int main(){
//     input();
//     x[0] = start;
//     visited[start] = 1;
//     travel(1);
//     output();
// }

/*Bài 3: Đếm số đường đi có chi phí nhỏ nhất*/
#include <stdio.h>
#include <stdlib.h>

#define inf INT_MAX
#define maxlen 1000

int visited[maxlen] = {0};
int x[maxlen]; //Chứa các kết quả thăm thành phố
int n, m, f = 0, best = inf, start = 1-1, cmin = inf;
int **a;

void input(){  
    scanf("%d", &n);
    a = (int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++) a[i] = (int*)malloc(n*sizeof(int)); 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &a[i][j]);
            if(a[i][j] < cmin) cmin = a[i][j];
        }
    }
}

void output(){
    printf("%d\n", best);
}

// void travel(int k){ //Kĩ thuật nhánh cận nhưng không tới =))
//     if(f > best) return;
//     for(int i=0; i<n; i++){
//         if(!visited[i] && a[x[k-1]][i] > 0){
//             x[k] = i;
//             visited[i] = 1;
//             f += a[x[k-1]][i];
//             if(k == n-1){
//                 if(f + a[x[n-1]][start] < best){
//                     best = f + a[x[n-1]][start];
//                 }
//             }
//             else travel(k+1);
//             visited[i] = 0;
//             f -= a[x[k-1]][i];
//         }
//     }
// }

void travel(int k){
    for(int i=0; i<n; i++){
        if(!visited[i] && a[x[k-1]][i] > 0){
            x[k] = i;
            visited[i] = 1;
            f += a[x[k-1]][i];
            if(k == n-1){
                if(f + a[x[n-1]][start] < best){
                    best = f + a[x[n-1]][start];
                }
            }
            else {
                int g = f + (n-k+1)*cmin;
                if(g < best) travel(k+1);
            }
            visited[i] = 0;
            f -= a[x[k-1]][i];
        }
    }
}

int main(){
    input();
    x[0] = start;
    visited[start] = 1;
    travel(1);
    output();
}