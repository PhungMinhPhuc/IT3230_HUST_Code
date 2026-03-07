/*Cho số nguyên dương n và M, hãy viết chương trình liệt kê tất cả các bộ X1, X2, …, Xn (theo thứ tự từ điển) sao cho X1 + X2 + . . . + Xn = M
Dữ liệu
Dòng 1: chứa số nguyên dương n và M (2 <= n <= 10, 1 <= M <= 20)
Kết quả
Ghi ra trên mỗi dòng một bộ giá trị của X1, X2, …, Xn (sau mỗi phần tử là 1 ký tự SPACE)
Ví dụ nhập vào:
3  5
thì kết quả là:
1 1 3
1 2 2
1 3 1
2 1 2
2 2 1
3 1 1*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define maxlen 10000

int n, x[maxlen], M;

int check(){
    int sum = 0;
    for(int i=1; i<=n; i++){
        sum += x[i];
    }
    if(sum == M) return 1;
    return 0;
}

void sol(){
    for(int i=1; i<=n; i++) printf("%d ", x[i]);
    printf("\n");
}

void try(int k){
    for(int i=1; i<=M-n+1; i++){
        x[k] = i;
        if(k == n){
            if(check() == 1){
                sol();
            }
        }
        else try(k+1);
    }
}

int main(){
    scanf("%d %d", &n, &M);
    try(1);
}