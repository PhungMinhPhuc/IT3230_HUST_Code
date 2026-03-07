/*Given a sequence of n integers a1, a2, ..., an, and a positive integer b. Compute the number Q of way to select some elements from the given sequence such that the sum of selected elements is equal to b.
Input
Line 1: contains 2 integers n and b (1 <= n <= 50, 1 <= b <= 100)
Line 2: contains n positive integer a1, a2, ..., an (1 <= ai <= 100)
Output
Write the value Q

Example
Input 
5 6
1 2 3 4 5
Output
3
*/

/*Cách 1: Đệ quy*/
// #include <stdio.h>

// #define maxlen 10000

// int n, b, cnt = 0, sum = 0;
// int a[maxlen];

// void count(int k) {
//     if (sum == b) {
//         cnt++;
//         return;
//     }
//     if(sum > b || k == n) return;
//     count(k + 1);
//     sum += a[k];
//     count(k + 1);
//     sum -= a[k];
// }

// int main(){
//     scanf("%d %d", &n, &b);
//     for(int i=0; i<n; i++){
//         scanf("%d", &a[i]);
//     }
//     count(0);
//     printf("%d", cnt);
// }

/*Cách 2: Quy hoạch động*/
#include <stdio.h>

#define maxlen 1000

int n, b, d[maxlen][maxlen], a[maxlen], count = 0, sum = 0;
//d[i][j] = số cách để tạo tổng sum từ các phần tử đầu tiên a[0..i-1]

void sol(){
    d[0][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=b; j++){
            d[i][j] = d[i-1][j];
            if(j >= a[i-1]) d[i][j] += d[i-1][j-a[i-1]];
        }
    }
}

int main(){
    scanf("%d %d", &n, &b);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    sol(0,0);
    printf("%d", d[n][b]);
}