/*Bài 5: (2đ) Để quản lý các nhân viên mật vụ, một cơ quan quy ước đánh số định danh cho từng nhân viên mật vụ như sau:
Ký tự đầu tiên là một chữ cái in hoa trong số các chữ cái: A, B, C, D, E
Theo sau đó là n chữ số, mỗi chữ số nhận giá trị là một trong các ký số: 1, 3, 5
Hãy viết chương trình C, đọc vào từ bàn phím một chữ cái và số nguyên dương n, sau đó liệt kê ra màn hình toàn bộ các tổ hợp số định danh theo thứ tự từ điển, mỗi tổ hợp trên một dòng.
Nếu chữ cái đã cho không phải chữ in hoa liệt kê ở trên thì hiển thị "Error" và kết thúc chương trình.
Ví dụ:
INPUT:
A
2
OUTPUT:
A11
A13
A15
A31
A33
A35
A51
A53
A55
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 100000

int a[] = {1, 3, 5}, x[maxlen], n;
char s[2];

void print(){
    printf("%s", s);
    for(int i=1; i<=n; i++){
        printf("%d", x[i]);
    }
    printf("\n");
}

void recursion(int k){
    for(int i=0; i<3; i++){
        x[k] = a[i];
        if(k == n){
            print();
        }
        else recursion(k+1);
    }
}

int main(){
    scanf("%s %d", s, &n);
    if(s[0]-'A' >=0 && s[0]-'E'<=0) recursion(1);
    else printf("Error");
}