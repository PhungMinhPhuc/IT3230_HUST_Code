/*Xếp N quân hậu vào một bàn cờ sao cho không có 2 quân hậu nào "ăn nhau" (cùng hàng, cùng cột, cùng đường chéo).
Đầu vào: Số nguyên N
Đầu ra gồm nhiều hàng, mỗi hàng là một dãy số có ý nghĩa là giá trị hàng của các quân hậu từ cột 1 đến cột N.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define maxlen 1000

int n, x[maxlen];

void sol(){
    for(int i=0; i<n; i++) printf("%d", x[i]+1);
    printf("\n");
}

int check(int hang, int cot){
    for(int i=0; i<cot; i++){
        if(hang == x[i] || abs(hang - x[i]) == abs(cot - i)) return 0;//cung hang hoac cung cheo
    }
    return 1;
}

void try(int k){
    for(int i=0; i<n; i++){
        if(check(i, k)){
            x[k] = i;
            if(k == n-1) sol();
            else try(k+1);
        }
    }
}

int main(){
    scanf("%d", &n);
    try(0);
}