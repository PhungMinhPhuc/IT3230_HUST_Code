/*There are two jugs, a-litres jug and b-litres jug (a, b are positive integers). There is a pump with unlimited water. Given a positive integer c, how to get exactly c litres.
Input
  Line 1: contains positive integers a, b, c  (1 <= a, b, c <= 900)
Output
  write the number of steps or write -1 (if no solution found)
Example

Input
6  8  4
Output
4*/

/*Có tổng cộng 6 trạng thái: fill A, B, empty A, B, pour A to B, pour B to A*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 1000

typedef struct state{
    int aState;
    int bState;
    int step;
} state;

state queue[maxlen];
int visited[maxlen][maxlen] = {0}, first = 0, last = -1;

void TryAndEnqueue(int newA, int newB, int CurrentStep){
    if(!visited[newA][newB]){
        visited[newA][newB] = 1;
        queue[++last] = (state){newA, newB, CurrentStep + 1};
    }
}

int bfs(int x, int y, int a, int b, int c){
    state startState = (state){x, y, 0};
    queue[++last] = startState;
    visited[x][y] = 1;
    while(first <= last){
        state current = queue[first++];
        if(current.aState == c || current.bState == c){
            printf("%d", current.step);
            return 0;
        }
        //Fill A
        TryAndEnqueue(a, current.bState, current.step);
        //Fill B
        TryAndEnqueue(current.aState, b, current.step);
        //Empty A
        TryAndEnqueue(0, current.bState, current.step);
        //Empty B
        TryAndEnqueue(current.aState, 0, current.step);
        //Pour A to B
        int pourAB = current.aState > b - current.bState ? b - current.bState : current.aState;
        TryAndEnqueue(current.aState - pourAB, current.bState + pourAB, current.step);
        //Pour B to A
        int pourBA = current.bState > a - current.aState ? a - current.aState : current.bState;
        TryAndEnqueue(current.aState + pourBA, current.bState - pourBA, current.step);
    }
    printf("-1");
    return 0;
}

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    bfs(0, 0, a, b, c);
}