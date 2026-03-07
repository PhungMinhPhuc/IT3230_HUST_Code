/*Number Transforming Of Couple
Viết chương trình thực hiện công việc sau:
Xét cặp số nguyên không âm viết tắt là (a,b). Thao tác trên cặp số bao gồm: thao tác I, II, III để chuyển (a,b) về (a-b,b) hoặc về (a+b,b) hoặc về (b,a). Lưu ý thao tác I thực hiện khi a >= b. Đầu vào là bốn số nguyên c, d, x, y, yêu cầu in ra các thao tác với số bước chuyển thao tác là ít nhất để chuyển đổi cặp (c,d) sang cặp (x,y) và chỉ dùng 3 loại thao tác I, II, III được định nghĩa ở trên. Nếu không có cách nào chuyển đổi được thì in ra -1.
Ví dụ c, d, x, y lần lượt là 14, 2, 2, 10 thì cần in ra tổng số bước chuyển và các thao tác lần lượt như sau: 3 (14 2) (12 2) (10 2) (2 10)
Input
Dòng 1: ghi 4 số nguyên không âm c, d, x, y (0 <= c, d, x, y <= 30)
Output
Ghi ra tổng số bước chuyển và các thao tác (hoặc -1 nếu không thể chuyển đổi)
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 10000

typedef struct couple{
    int a, b, step;
} couple;

couple queue[maxlen], parent[maxlen][maxlen];
int dau = 0, cuoi = -1, k = 0, visited[101][101] = {0};

void printpath(couple u, int c, int d, int x, int y){
    if(c == u.a && d == u.b){
        printf("(%d %d) ", u.a, u.b);
        return;
    }
    couple p = parent[u.a][u.b];
    printpath(p, c, d, x, y);
    printf("(%d %d) ", u.a, u.b);
}

int bfs(int c, int d, int x, int y){
    couple s = (couple){c, d, 0};
    visited[c][d] = 1;
    queue[++cuoi] = s;
    while(dau <= cuoi){
        couple u = queue[dau++];
        if(u.a == x && u.b == y){
            printf("%d ", u.step);
            printpath(u, c, d, x, y);
            return 0;
        }
        if(u.a >= u.b && u.a - u.b <= 30 && !visited[u.a-u.b][u.b]){
            queue[++cuoi] = (couple){u.a-u.b, u.b, u.step+1};
            visited[u.a-u.b][u.b] = 1;
            parent[u.a-u.b][u.b] = (couple){u.a, u.b, 0};
        }
        if(u.a + u.b <= 30 && !visited[u.a+u.b][u.b]){
            queue[++cuoi] = (couple){u.a+u.b, u.b, u.step+1};
            visited[u.a+u.b][u.b] = 1;
            parent[u.a+u.b][u.b] = (couple){u.a, u.b, 0};
        }
        if(u.a <= 30 && u.b <= 30 && !visited[u.b][u.a]){
            queue[++cuoi] = (couple){u.b, u.a, u.step+1};
            visited[u.b][u.a] = 1;
            parent[u.b][u.a] = (couple){u.a, u.b, 0};
        }
    }
    printf("-1\n");
    return 0;
}

int main(){
    int c, d, x, y;
    scanf("%d %d %d %d", &c, &d, &x, &y);
    if(c == 0 && d == 0 && x == 0 && y == 0){
        printf("\n0 (0 0)");
        return 0;
    }
    bfs(c, d, x, y);
}