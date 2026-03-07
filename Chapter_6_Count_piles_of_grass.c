/*Có n bó cỏ đặt ở các vị trị khác nhau trên con đường thẳng từ đầu đến cuối cánh đồng. Cho hai số A và B cần xác định xem có bao nhiêu bó cỏ nằm từ vị trí A đến vị trí B.
Dữ liệu vào:
Dòng đầu tiên gồm 2 số nguyên dương n và m (<= 10^5) là số bó cỏ và số câu hỏi.
Dòng tiếp theo gồm n số nguyên không âm a1...an là vị trí các bó cỏ (0<=ai<=10^9)
m dòng tiếp theo, mỗi dòng là 2 số nguyên A, B (0 <= A, B <= 10^9)
Kết quả:
Ghi ra m dòng là câu trả lời cho m câu hỏi tương ứng.
Input:
5 3
1 3 5 7 9
2 6
0 10
4 4
Output:
2
5
0
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 100001

int a[maxlen], b[2][maxlen], n, m;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int i, int a[], int n){
    int largest = i, left = 2*i+1, right = 2*i+2;
    if(left < n && a[largest] < a[left]) largest = left;
    if(right < n && a[largest] < a[right]) largest = right;
    if(i != largest){
        swap(&a[i], &a[largest]);
        heapify(largest, a, n);
    }
}

void heapSort(){
    for(int i=n/2-1; i>=0; i--) heapify(i, a, n);
    for(int i=n-1; i>0; i--){
        swap(&a[0], &a[i]);
        heapify(0, a, i);
    }
}

int lower_bound(int a[], int left, int right, int A){
    while(left < right){
        int m = (left + right)/2;
        if(a[m] < A) left = m+1;
        else right = m;
    }
    return left;
}

int upper_bound(int a[], int left, int right, int B){
    while(left < right){
        int m = (left + right)/2;
        if(a[m] <= B) left = m+1;
        else right = m;
    }
    return left;
}

void input(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    for(int i=0; i<m; i++){
        scanf("%d %d", &b[0][i], &b[1][i]);
    }
}

int main(){
    input();
    heapSort();
    for(int i=0; i<m; i++){
        printf("%d\n", upper_bound(a, 0, n, b[1][i]) - lower_bound(a, 0, n, b[0][i]));
    }
    return 0;
}