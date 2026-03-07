#include <stdio.h>
#include <stdlib.h>

#define maxlen 1000

int n, count = 0;
int a[maxlen][maxlen];

int check(int x, int y){
    for(int i=0; i<n; i++) if(a[i][y] == 1) return 0;
    for(int j=0; j<n; j++) if(a[x][j] == 1) return 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if((abs(x-i) == abs(y-j)) && a[i][j] == 1) return 0;
        }
    }
    return 1;
}

void sol(int r){
    if(r == n){
        count ++;
        return;
    }
    for(int c=0; c<n; c++){
        if(a[r][c] == 1) sol(r+1);
        else if(check(r, c)){
            a[r][c]=1;
            sol(r+1);
            a[r][c]=0;
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    sol(0);
    printf("%d", count);
}