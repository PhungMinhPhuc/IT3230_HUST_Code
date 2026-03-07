/*Cho n ván gỗ có chiều dài lần lượt là a(1), a(2), ..., a(n) đơn vị độ dài (0 <= a(i) <= 10^5). Ta có thể ghép hai ván gỗ có chiều dài a(i) và a(j) thành một ván gỗ mới có chiều dài là a(i) + a(j) và tốn chi phí là a(i) + a(j). Hỏi chi phí nhỏ nhất để ghép n ván gỗ đã cho thành một ván gỗ duy nhất là bao nhiêu?
Đầu vào gồm 2 dòng, dòng 1 là số nguyên dương n, dòng sau gồm n giá trị a(1), ....a(n)
Ví dụ:
6
1 2 8 2 7 6
Đầu ra là chi phí nhỏ nhất:
60*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 100001

int a[maxlen], n;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int heapify(int i, int a[], int n){
    int smallest = i, left = 2*i+1, right = 2*i+2;
    if(left < n && a[smallest] > a[left]) smallest = left;
    if(right < n && a[smallest] > a[right]) smallest = right;
    if(i != smallest){
        swap(&a[i], &a[smallest]);
        heapify(smallest, a, n);
    }
}

int lowest_cost(int a[], int n){
    for(int i=n/2-1; i>=0; i--) heapify(i, a, n);
    int total = 0;
    while(n > 1){
        int x = a[0];
        a[0] = a[--n];
        heapify(0, a, n);
        int y = a[0];
        int sum = x + y;
        a[0] = sum;
        heapify(0, a, n);
        total += sum;
    }
    return total;
}

void input(){
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
}

int main(){
    input();
    printf("%d\n", lowest_cost(a, n));
    return 0;
}