/*Cho số nguyên dương n và M, hãy viết chương trình liệt kê tất cả các bộ X1, X2, …, Xn (theo thứ tự từ điển, không trùng lặp) sao cho X1 + X2 + . . . + Xn = M
Dữ liệu
Dòng 1: chứa số nguyên dương n và M (2 <= n <= 10, 1 <= M <= 20)
Kết quả
Ghi ra trên mỗi dòng một bộ giá trị của X1, X2, …, Xn (sau mỗi phần tử là 1 ký tự SPACE)
Ví dụ nhập vào:
3  5
thì kết quả là:
1 1 3
1 2 2*/
#include <stdio.h>

#define maxlen 20

int n, M, T, a[maxlen];

void print(){
    for(int i=1; i<=n; i++) printf("%d ", a[i]);
    printf("\n");
}

int check(int v, int k){
    if(k<n) return 1;
    else return T + v == M;
}

void sol(int k){
    for(int i=a[k-1]; i<=M-T-n+k; i++){
        if(check(i,k)){
            a[k]=i;
            T=T+i;
            if(k == n) print();
            else sol(k+1);
            T=T-i;
        }
    }
}

int main()
{
    scanf("%d %d", &n, &M);
    T = 0;
    a[0] = 1;
    sol(1);
    return 0;
}