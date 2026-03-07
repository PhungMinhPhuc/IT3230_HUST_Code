/*Câu 3 (2.5 điểm): Tìm số gần nhất
Cho mảng dãy số nguyên a1, a2, ..., an. Với mỗi giá trị k, hãy tìm phần tử trong dãy có giá trị gần k nhất.
Đầu vào:
- Dòng đầu chứa n là số phần tử của dãy (1 ≤ n ≤ 1.000.000)
- Dòng thứ hai chứa n phần tử của dãy (1 ≤ ai ≤ 10.000.000)
- Các dòng tiếp theo chứa các lệnh tìm kiếm theo định dạng SEARCH <value> (1 ≤ value ≤ 10.000.000) kết thúc bởi dòng có nội dung "#"
Đầu ra:
- |k - ai| trong đó ai là phần tử có giá trị gần k nhất
Ví dụ:
Đầu vào:
5
1 4 3 1 4
SEARCH 0
SEARCH 1
SEARCH 5
SEARCH 2
SEARCH 10
#
Đầu ra:
1
0
1
1
6*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define maxlen 10000

int binarySearch(int a[], int n, int x){
    int l = 0, r = n;
    while(l < r){
        int m = (l+r)/2;
        if(a[m] <= x) l = m + 1;
        else r = m;
    }
    return l;
}

int cmp(void const* ptr1, void const* ptr2){
    int* x = (int*)ptr1;
    int* y = (int*)ptr2;
    return *x - *y;
}

int main(){
    int n, a[maxlen];
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    char c[maxlen];
    while(1){
        scanf("%s", c);
        if(strcmp(c, "#") == 0) break;
        if(strcmp(c, "SEARCH") == 0){
            int x;
            scanf("%d", &x);
            int target = binarySearch(a, n, x);
            if(target == 0) printf("%d\n", abs(a[0] - x));
            else if(target == n) printf("%d\n", abs(x - a[n-1]));
            else{
                printf("%d\n", (abs(a[target - 1] - x) < abs(a[target] - x) ? abs(a[target - 1] - x) : abs(a[target] - x)));
            }
        }
    }
}