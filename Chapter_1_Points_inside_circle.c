/*Cho n điểm với tọa độ (xi, yi) và m đường tròn (ui, vi, ri), tâm ui, v­i, bán kính ri. Đếm xem có bao nhiêu điểm nằm trong hoặc trên ít nhất một đường tròn. Đầu vào có dòng đầu chứa n (n < 1000). N dòng tiếp chứa tọa độ của n điểm với tung độ và hoành độ cách nhau bởi dấu cách. Dòng tiếp theo chứa m (m < 1000). M dòng tiếp theo chứa tọa độ tâm và bán kính của m đường tròn, cách nhau bởi dấu cách. Chương trình in ra số điểm thỏa mãn yêu cầu, nếu không có điểm nào in ra 0.
Ví dụ:
INPUT:
5
1 1
2 2
3 3
4 4
5 5
4
1 2 2
2 2 2
4 3 2
4 3 3
OUTPUT:
5
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define maxlen 10000

typedef struct cir{
    int x, y, r;
} cir;

typedef struct point{
    int x, y;
} point;

int main(){
    int n, m, visited[maxlen] = {0}, cnt = 0;
    scanf("%d", &n);
    point a[maxlen];
    cir b[maxlen];
    for(int i=0; i<n; i++) scanf("%d %d", &a[i].x, &a[i].y);
    scanf("%d", &m);
    for(int i=0; i<m; i++) scanf("%d %d %d", &b[i].x, &b[i].y, &b[i].r);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!visited[j] && (pow(b[i].x - a[j].x, 2) + pow(b[i].y - a[j].y, 2)) <= pow(b[i].r, 2)){
                visited[j] = 1;
                cnt++;
            }
        }
    }
    printf("%d", cnt);
}