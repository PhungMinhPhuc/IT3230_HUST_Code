/*Bài 1: (1đ) Viết một chương trình C đọc vào từ bàn phím một số nguyên dương n, hiển thị ra màn hình tất cả các số nguyên dương chẵn ∈ [1, n], mỗi số trên một dòng, lần lượt từ số nhỏ đến số lớn.
Ví dụ:
INPUT:
8
OUTPUT:
2
4
6
8
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 100000

int main(){
    int n;
    scanf("%d", &n);
    for(int i=2; i<=n; i+=2){
        printf("%d\n", i);
    }
}