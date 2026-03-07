/*Replace ? To Find Real Expression
Viết chương trình thực hiện công việc sau:
Một biểu thức chứa các kí tự ngoặc mở '(' hoặc ngoặc đóng ')' được gọi là biểu thức ngoặc đúng nếu chúng đóng mở hợp lý, ví dụ biểu thức (()) hoặc ()() đều là biểu thức ngoặc đúng. Với đầu vào là một xâu kí tự độ dài n lưu trong dãy a1, a2, ..., an gồm 3 số 0, 1, 2 ứng với 3 loại kí tự là dấu hỏi '?' hoặc  kí tự ngoặc mở '(' hoặc ngoặc đóng ')' , yêu cầu in ra tất cả các trường hợp là biểu thức ngoặc đúng khi thay kí tự dấu hỏi bằng ngoặc đóng hoặc ngoặc mở dưới dạng các con số tương ứng.
Ví dụ 1002 ứng với (??) sẽ in ra 1122 và 1212 ứng với (()) và ()().
Input
Dòng 1: ghi số nguyên dương n (1 <= n <= 100)
Dòng 2: ghi các số nguyên dương a
Output
Ghi ra dãy các biểu thức ngoặc đúng
-----------------------------------
Example:
Input
4
1 0 0 2
Output
1122 1212
*/

//Cách 1: Đệ quy dùng cắt nhánh
// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// #include <stdlib.h>

// #define maxlen 10000
// int a[maxlen], stack[maxlen];
// int n, m = 0;

// void try(int k, int o, int c){
//     if(k == n){
//         if(o == c){
//             for(int i=0; i<n; i++) printf("%d", a[i]);
//             printf(" ");
//         }
//     }
//     if(a[k] == 0){
//         if(o < n/2){
//             a[k] = 1;
//             try(k+1, o+1, c);
//         }
//         if(o > c){
//             a[k] = 2;
//             try(k+1, o, c+1);
//         }
//         a[k] = 0;
//     }
//     if(a[k] == 1) try(k+1, o+1, c);
//     if(a[k] == 2 && o > c) try(k+1, o, c+1); 
// }

// int main(){
//     scanf("%d", &n);
//     for(int i=0; i<n; i++) scanf("%d", &a[i]);
//     try(0, 0, 0);
//     printf("\n");
// }

//Cách 2: Quy hoạch động

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 10000

int dp[maxlen][maxlen] = {0}, bal, n, a[maxlen], trace[maxlen];//bal là số ngoặc mở chưa đóng, i là vị trí kí tự đang xét
//trước đó bal = 1 thì mới có cách đặt bal hiện tại, còn nếu trước đó không có cách thì sẽ không đặt được cái hiện tại

void try(){
    dp[n+1][0] = 1;
    for(int i=n; i>0; i--){
        for(int bal = 0; bal <= n; bal++){
            if(a[i] == 1){
                if(bal < n) dp[i][bal] = dp[i+1][bal+1];
            } 
            else if(a[i] == 2){
                if(bal > 0) dp[i][bal] = dp[i+1][bal-1];
            }
            else if(a[i] == 0){
                if(bal < n && dp[i+1][bal+1] == 1) dp[i][bal] = 1;
                if(bal > 0 && dp[i+1][bal-1] == 1) dp[i][bal] = 1;
            }
        }
    }
}

void backtrack(int i, int bal){
    if(i > n){
        for(int j=1; j<=n; j++) printf("%d", trace[j]);
        printf(" ");
        return;
    }
    if(bal < n && dp[i+1][bal+1] == 1){
        trace[i] = 1;
        backtrack(i+1, bal+1);
    }
    if(bal > 0 && dp[i+1][bal-1] == 1){
        trace[i] = 2;
        backtrack(i+1, bal-1);
    }
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    try();
    backtrack(1, 0);
    printf("\n");
}