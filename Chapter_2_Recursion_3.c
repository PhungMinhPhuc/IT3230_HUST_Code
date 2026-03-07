/*Cho một số nguyên dương n (<=10).
Hãy in ra số lượng các chuỗi nhị phân độ dài n mà có tổng các chữ số của nửa trái và nửa phải bằng nhau.
Nếu n lẻ thì chữ số nhị phân nằm chính giữa không tính vào nửa nào.
Các chuỗi được in ra theo thứ tự tăng dần (alphabet) và mỗi chuỗi trên 1 dòng.
Ví dụ:
n = 4 thì in ra 6 ứng với các chuỗi sau
0000 
0101 
0110 
1001 
1010 
1111
n = 5 thì in ra 12 ứng với các chuỗi sau
00000 
00100 
01001 
01101 
01010 
01110 
10001 
10101 
10010 
10110 
11011 
11111*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define maxlen 10000

int n, x[maxlen], count = 0;

int check(){
    int rightSum = 0, leftSum = 0;
    for(int i=1; i<=n/2; i++){
        rightSum += x[i];
        leftSum += x[n-i+1];
    }
    if(rightSum == leftSum) return 1;
    return 0;
}

void sol(){
    for(int i=1; i<=n; i++) printf("%d", x[i]);
    printf("\n");
}

void try(int k){
    for(int i=0; i<2; i++){
        x[k] = i;
        if(k == n){
            if(check() == 1){
                // sol();
                count ++;
            }
        }
        else try(k+1);
    }
}

int main(){
    scanf("%d", &n);
    try(1);
    printf("%d", count);
}