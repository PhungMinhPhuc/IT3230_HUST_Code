/*Calculate the nth (n < 100) value with modular (10^9 + 7) in Fibonacci series.
F(1) = 1, F(2) = 1
F(n) = F(n-1) + F(n-2).
Input:
3
Output:
2*/

/*Cách 1: Đệ quy*/
// #include <stdio.h>
// #include <math.h>
// #include <ctype.h>
// #include <stdlib.h>

// #define maxlen 10000
// #define MOD 1000000007

// int n;

// int fib(int n){
//     if(n == 1 || n == 2) return 1;
//     else return fib(n-1) + fib(n-2);
// }

// int main(){
//     scanf("%d", &n);
//     printf("%d", fib(n)%MOD);
// }

/*Cách 2: Quy hoạch động*/
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 10000
#define MOD 1000000007

int main(){
    int n, dp[maxlen];
    scanf("%d", &n);
    dp[1] = 1, dp[2] = 1;
    for(int i=3; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }
    printf("%d", dp[n]);
}