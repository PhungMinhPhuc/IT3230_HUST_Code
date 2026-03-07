/*Cho n đường tròn. Hãy tìm đường tròn giao với nhiều đường tròn còn lại nhất. In ra số lần giao.
Hai đường tròn giao nhau khi |R1-R2| < Khoảng cách tâm < R1+R2
VD:
Input:
3
1 1 1
3 2 2
5 1 1
Output:
2*/

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 10000

typedef struct cir{
    int x, y, r;
} cir;

int main(){
    int n, cnt = 0, max = -1e9;
    cir a[maxlen];
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].r);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i != j && (pow(a[i].x - a[j].x, 2) + pow(a[i].y - a[j].y, 2)) < pow((a[i].r + a[j].r), 2) && (pow(a[i].x - a[j].x, 2) + pow(a[i].y - a[j].y, 2)) > pow((a[i].r - a[j].r), 2)){
                cnt++;
            }
        }
        if(cnt > max) max = cnt;
        cnt = 0;
    }
    printf("%d", max);
}