/*Write a program that generates all permutations of 1, 2, ..., n in a lexicographic order such that there are no 2 consecutive even elements.
Input
A line contains a positive integer n (2 <= n <= 9)
Output
Each line contains a permutation, elements a re separated by a SPACE character*/

#include <stdio.h>

#define maxlen 10000

int x[maxlen], n, used[maxlen] = {0};

void print(){
    for(int i=1; i<=n; i++){
        printf("%d ", x[i]);
    }
    printf("\n");
}

void sol(int k){
    for(int i=1; i<=n; i++){
        if(!used[i]){
            x[k] = i;
            used[i] = 1;
            if(k>1 && (x[k-1] % 2 == 0 && x[k]%2 == 0)){
                used[i] = 0;
                continue;
            }
            if(k == n) print();
            else sol(k+1);
            used[i] = 0;
        }
    }
}

int main(){
    scanf("%d", &n);
    sol(1);
}