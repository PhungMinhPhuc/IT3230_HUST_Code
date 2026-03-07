/*Print all the odd hexa deximal number of length n (n < 10) in decreasing order of lexicography.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define maxlen 10000

int x[12];
int n;

void sol(){
    for(int i=1; i<=n; i++) printf("%X", x[i]);
    printf("\n");
}

void try(int k){
    for(int i=15; i>=0; i--){
        if(k == n+1){
            if(x[n]%2 == 1) sol();
            return;
        }
        x[k] = i;
        try(k+1);
    }
}

int main(){
    scanf("%d", &n);
    try(1);
}