/*Convert a postive integer into hexa decimal base.
Input:
20
Output:
14
Input: 
15
Output:
F*/

#include <stdio.h>

#define maxlen 10000

int main(){
    int n, x[maxlen], count = 0;
    scanf("%d", &n);
    while(n > 0){
        x[count] = n%16;
        n /= 16;
        count ++;
    }
    for(int i=count - 1; i>=0; i--) printf("%X", x[i]);
}