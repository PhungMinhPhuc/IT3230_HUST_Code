#include <stdio.h>
#define maxlen 1000

int x[maxlen];
int n;
int used[maxlen];

void print(){
    for(int i=1; i<=n; i++){
        printf("%d ", x[i]);
    }
    printf("\n");
}

void try(int k){
    for(int i=1; i<=n; i++){
        if(!used[i] && ((k%2 == 0 && i%2 == 0) || (k%2 == 1 && i%2 == 1))){
            x[k] = i;
            used[i] = 1;
            if(k == n) print();
            else try(k+1);
            used[i]=0;
        }
    }
}

int main(){
    scanf("%d", &n);
    try(1);
    return 0;
}
