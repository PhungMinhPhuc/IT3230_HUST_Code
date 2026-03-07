/*Một mê cung hình chữ nhật được biểu diễn bởi 0-1 ma trận NxM trong đó A[i,j] = 1 thể hiện ô (i,j) là tường gạch và A[i,j] = 0 thể hiện ô (i,j) là ô trống, có thể di chuyển vào. Từ 1 ô trống, ta có thể di chuyển sang 1 trong 4 ô lân cận (lên trên, xuống dưới, sang trái, sang phải) nếu ô đó là ô trống. Xuất phát từ 1 ô trống trong mê cung, hãy tìm đường ngắn nhất thoát ra khỏi mê cung.

Input
Dòng 1: ghi 4 số nguyên dương n, m, r, c trong đó n và m tương ứng là số hàng và cột của ma trận A (1 <= n,m <= 999) và r, c tương ứng là chỉ số hàng, cột của ô xuất phát.
Dòng i+1 (i=1,...,n): ghi dòng thứ i của ma trận A

Output
Ghi giá số bước cần di chuyển ngắn nhất để thoát ra khỏi mê cung, hoặc ghi giá trị -1 nếu không tìm thấy đường đi nào thoát ra khỏi mê cung.

Ví dụ

Input
8 12 5 6
1 1 0 0 0 0 1 0 0 0 0 1
1 0 0 0 1 1 0 1 0 0 1 1
0 0 1 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 1 0 0 1 0 1
1 0 0 1 0 0 0 0 0 1 0 0
1 0 1 0 1 0 0 0 1 0 1 0
0 0 0 0 1 0 1 0 0 0 0 0
1 0 1 1 0 1 1 1 0 1 0 1

Output
7*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 1000000

typedef struct state{
    int i;
    int j;
    int step;
} state;

state queue[maxlen];
int maze[1000][1000];
int first = 0, last = -1, visited[1000][1000] = {0};

void TryAndEnqueue(int new_i, int new_j, int currentStep){
    if(!visited[new_i][new_j] && maze[new_i][new_j] != 1){
        visited[new_i][new_j] = 1;
        queue[++last] = (state){new_i, new_j, currentStep + 1};
    }
}

int bfs(int row, int column, int n, int m){
    state start = (state){row, column, 0};
    queue[++last] = start;
    visited[row][column] = 1;
    while(first <= last){
        state current = queue[first++];
        if(current.i == 0 || current.i == n-1 || current.j == 0 || current.j == m-1){
            printf("%d", current.step + 1);
            return 0;
        }
        //Up
        TryAndEnqueue(current.i - 1, current.j, current.step);
        //Down
        TryAndEnqueue(current.i + 1, current.j, current.step);
        //Left
        TryAndEnqueue(current.i, current.j - 1, current.step);
        //Right
        TryAndEnqueue(current.i, current.j + 1, current.step);
    }
    printf("-1");
    return 0;
}


int main(){
    int n, m, r, c;
    scanf("%d %d %d %d", &n, &m, &r, &c);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &maze[i][j]);
        }
    }
    bfs(r-1, c-1, n, m);
}