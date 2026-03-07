/*Cho số N và N đoạn được định nghĩa bởi giá trị bắt đầu và kết thúc. Hãy in ra giá trị TRUE nếu trong N đoạn này có 2 đoạn chồng nhau, hoặc FALSE nếu không có bất kỳ 2 đoạn nào trong số N đoạn chồng nhau. 
Dữ liệu đầu vào:
- Dòng 1 gồm số nguyên dương N không quá 1000000
- N dòng sau mỗi dòng gồm 2 số nguyên trong khoảng -1000000 đến 1000000
Dữ liệu ví dụ như sau:
4
1 3
5 7
2 4
6 8
In ra: TRUE
4
1 3
7 9
4 6
10 13
In ra: FALSE*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 1000001

typedef struct data
{
    int start;
    int end;
} data;

data a[maxlen];
int n;

void swap(data* a, data* b){
    data temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int i, int n){
    int largest = i, left = 2*i+1, right = 2*i+2;
    if(left < n && a[largest].start < a[left].start) largest = left;
    if(right < n && a[largest].start < a[right].start) largest = right;
    if(i != largest){
        swap(&a[i], &a[largest]);
        heapify(largest, n);
    }
}

void heapSort(){
    for(int i=n/2-1; i>=0; i--) heapify(i, n);
    for(int i=n-1; i>0; i--){
        swap(&a[0], &a[i]);
        heapify(0, i);
    }
}

void input(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &a[i].start, &a[i].end);
    }
}

int main(){
    input();
    heapSort();
    int max_end = a[0].end;
    for(int i=1; i<n; i++){
        if(a[i].start > max_end) max_end = a[i].end;
        else{
            printf("TRUE\n");
            return 0;
        }
    }
    printf("FALSE\n");
    return 0;
}