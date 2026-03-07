/*Cho n quả táo có trọng lượng là a1, a2, ...., an.
Hãy chia n quả táo thành 2 phần sao cho chênh lệch trọng lượng giữa 2 phần là nhỏ nhất có thể.
Input:
- Dòng đầu chứa số nguyên dương n <= 20
- Dòng sau chứa n số nguyên dương (<=1000) cách nhau bởi dấu cách
Output:
1 số nguyên duy nhất là giá trị tuyệt đối của chênh lệch*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define maxlen 10000

int n, a[maxlen], x[21], sum = 0, f = 0, min = 1e9;

void try(int k){
    if(k == n){
        if(abs((sum - f) - f) < min) min = abs((sum - f) - f);
        return;
    }
    f += a[k];
    try(k+1);
    f -= a[k];
    try(k+1);
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    try(0);
    printf("%d", min);
}