/*Bài toán balo(Knapsack): Có N món quà với kích thước và giá trị lần lượt là S1, S2,…SN và V1, V2,…VN. Bạn có một balo có khả năng đựng tối đa là M. Hãy tìm cách cho vào balo các món quà để có thể có tổng giá trị quà là lớn nhất. Chỉ có thể cho nguyên vẹn 1 món quà mà không thể chia nhỏ ra được. Đầu vào chương trình:
Dòng đầu gồm 2 số nguyên N và M cách nhau bởi dấu cách (N < 1000, M < 10000)
N dòng sau mỗi dòng gồm một cặp Si và Vi (i=1,2,…N) cách nhau bởi dấu cách.
Chương trình cần in giá trị quà lớn nhất đạt được. Nếu balo không đủ chứa bất kỳ món quà nào thì in ra 0.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define maxlen 10000

typedef struct inf{
    int s, v;
} inf;

int n, m, x[21], size = 0, value = 0, max = -1e9;
inf a[maxlen];

void try(int k){
    if(k == n){
        if(size <= m && value >= max) max = value;
        return;
    }
    size += a[k].s;
    value += a[k].v;
    try(k+1);
    size -= a[k].s;
    value -= a[k].v;
    try(k+1);
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        scanf("%d %d", &a[i].s, &a[i].v);
   }
    try(0);
    printf("%d", max);
}