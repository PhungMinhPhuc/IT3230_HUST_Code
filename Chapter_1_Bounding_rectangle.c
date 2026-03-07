/*Cho một danh sách các hình chữ nhật 1, 2,…, n. Hãy tìm diện tích hình chữ nhật nhỏ nhất bao tất cả các hình chữ nhật trong danh sách trên
Dữ liệu
· Dòng 1: chứa số nguyên dương n (1 <= n <= 1000)
· Dòng i+1 (i=1,…,n): chứa 4 số nguyên dương x1,y1, x2,y2 trong đó (x1,y1) và (x2,y2) là tọa độ 2 đỉnh đối của hình chữ nhật thứ i (1 <= x1, y1, x2, y2 <= 100)
Kết quả
· Ghi ra diện tích của hình chữ nhật nhỏ nhất tìm được
Ví dụ
Dữ liệu
3
2 4 2 7
3 2 4 7
1 2 5 2
Kết quả
20*/

#include <stdio.h>
#include <stdlib.h>

#define inf 10000009

typedef struct rec{
    int x1;
    int y1;
    int x2;
    int y2;
} rec;

int main(){
    int n, xmin = inf, xmax = -inf, ymin = inf, ymax = -inf;
    scanf("%d", &n); 
    rec *a = (rec*)malloc(1000*sizeof(rec));
    for(int i=0; i<n; i++){
        scanf("%d %d %d %d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
        if(a[i].x1 < xmin) xmin = a[i].x1;
        if(a[i].x2 < xmin) xmin = a[i].x2;
        if(a[i].y1 < ymin) ymin = a[i].y1;
        if(a[i].y2 < ymin) ymin = a[i].y2;
        if(a[i].x1 > xmax) xmax = a[i].x1;
        if(a[i].x2 > xmax) xmax = a[i].x2;
        if(a[i].y1 > ymax) ymax = a[i].y1;
        if(a[i].y2 > ymax) ymax = a[i].y2;
    }
    printf("%d", (xmax-xmin)*(ymax-ymin));
    free(a);
}