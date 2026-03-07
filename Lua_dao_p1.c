#include <stdio.h>
int v, n, cnt, a[100];

void try(int k){
    for (v = 0; v<=1; v++){
        a[k] = v;
        if(k == n) cnt ++;
        else try(k+1);
    }
}

int main(){
    n = 3;
    cnt = 0;
    try(1);
    printf("%d\n", cnt);
    printf("%d", v);
}
/*Ra kết quả là 8 => Gà*/