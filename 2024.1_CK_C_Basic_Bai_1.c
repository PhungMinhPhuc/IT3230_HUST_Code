/*Bài 1: (1đ)
Viết một chương trình C đọc vào từ bàn phím một số nguyên dương N, hiển thị ra màn hình tổng giá trị tất cả các số nguyên dương chẵn ∈ [1, N].
Ví dụ:
INPUT:
8
OUTPUT:
20
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 10000

int main(){
    int n, evenSum = 0;
    scanf("%d", &n);
    for(int i=0; i<=n; i+=2){
        evenSum += i;
    }
    printf("%d\n", evenSum);
}