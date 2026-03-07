/*Tim va dem so tap con của 1 day va in ra man hinh*/
#include <stdio.h>
#define maxlen 10000
int n, b, cnt = 0, sum = 0, x[maxlen];
int a[maxlen];

void print(int size){
    for(int i=0; i<n; i++){
        if(x[i]) printf("%d", a[i]);
    }
    printf("\n");
}

void subset(int k){
        if(k == n){
            print(k);
            return;
        }
        x[k] = 0;
        subset(k+1);
        x[k] = 1;
        subset(k+1);
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    subset(0);
    printf("%d", cnt);
}