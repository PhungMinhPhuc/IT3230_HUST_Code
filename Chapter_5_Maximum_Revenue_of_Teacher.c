/*Thầy Vinh dự định thu học phí của N sinh viên. 
Mỗi sinh viên (i) có một giá trị A(i) là mức tiền học phí cao nhất có thể trả để đi học.
Nếu Thầy Vinh thu mức học phí C thì chỉ những sinh viên nào có A(i)>=C mới đi học và thanh toán học phí.
Hãy giúp Thầy Vinh chọn  mức học phí để thu được nhiều tiền nhất có thể.
Đầu vào gồm 2 dòng:
- Dòng 1 là số sinh viên (N là số nguyên dương không quá 10^5)
- Dòng 2 gồm N số nguyên dương A(i) không quá 10^6
Đầu ra gồm 2 giá trị cách nhau bởi dấu cách: <Tổng số tiền thu được> <Mức học phí>
Nếu có nhiều hơn một mức học phí cùng cho một giá trị tổng tiền thu về thì lựa chọn kết quả ứng với mức học phí thấp nhất.
Ví dụ vào là
4
1 6 4 6
Thì ra là
12 4*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 100000

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int i, int *a, int n){
    int left = 2*i+1, right = 2*i+2, largest = i;
    if(left < n && a[left] > a[largest]) largest = left;
    if(right < n && a[right] > a[largest]) largest = right;
    if(largest != i){
        swap(&a[largest], &a[i]);
        heapify(largest, a, n);
    }
}

void heapsort(int *a, int n){
    for(int i=n/2-1; i>=0; i--){
        heapify(i, a, n);
    }
    for(int i = n-1; i>0; i--){
        swap(&a[0], &a[i]);
        heapify(0, a, i);
    }
}

int main(){
    int n, maxRevenue = 0, minTiution;
    scanf("%d", &n);
    int a[maxlen];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    heapsort(a, n);
    for(int i=0; i<n; i++){
        int tuition = a[i];
        int revenue = tuition*(n-i);
        if(maxRevenue < revenue){
            maxRevenue = revenue;
            minTiution = tuition;
        }
    }
    printf("%d %d\n", maxRevenue, minTiution);
}