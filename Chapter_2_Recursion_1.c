/*Cho một số nguyên K. Tạo tất cả các chuỗi nhị phân có kích thước k mà không có số 1 liên tiếp.
Đầu vào: Số nguyên K (1 <= K <= 10)
Đầu ra: Mỗi chuỗi trên 1 dòng, các xâu "tăng dần" theo thứ tự alphabet từ trên xuống.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define maxlen 10000

int n, x[maxlen];

void sol(){
    for(int i=1; i<=n; i++) printf("%d", x[i]);
    printf("\n");
}

void try(int k){
    for(int i=0; i<2; i++){
        x[k] = i;
        if(k > 1 && x[k-1] == 1 && x[k] == 1) continue;
        if(k == n) sol();
        else try(k+1);
    }
}

int main(){
    scanf("%d", &n);
    try(1);
}