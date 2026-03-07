/*Write C program that reads an integer value N from stdin, prints to stdout the number Q ways to assign values 1, 2, …, 9 to characters I, C, T, H, U, S, K (characters are assigned with different values) such that: ICT - K62 + HUST = N
Input
Unique line contains an integer N (1 <= N <= 10^5)
Output
Write the value Q
Example
Input
2000
Output
28
*/

#include <stdio.h>
#include <string.h>

int n, count=0, x[9], used[11] = {0};

void sol(int k){
    for(int i=1; i<10; i++){
        if(!used[i]){
            x[k] = i;
            used[i] = 1;
            if(k == 7 && ((x[1]*100 + x[2]*10+x[3]) - (x[4]*100+62) + (x[5]*1000 + x[6]*100 + x[7]*10 + x[3]) == n)) count ++;
            else sol(k+1);
            used[i] = 0;
        }
    }
}

int main(){
    scanf("%d", &n);
    sol(1);
    printf("%d", count);
}