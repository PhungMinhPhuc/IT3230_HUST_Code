/*Viết chương trình thực hiện công việc sau:
Một biểu thức chứa các kí tự ngoặc mở '(' '{' '[' hoặc ngoặc đóng '}' ']' ')' được gọi là biểu thức ngoặc đúng nếu chúng đóng mở hợp lý, ví dụ biểu thức ([{}]) hoặc (){}[()] đều là biểu thức ngoặc đúng. Với đầu vào là một xâu kí tự độ dài n lưu trong dãy a1, a2, ..., an gồm 7 số 0, 1, 2, 3, 4, 5, 6  ứng với 7 loại kí tự là dấu hỏi '?' và các kí tự ngoặc mở lần lượt là  '(' '{' '[' và ngoặc đóng lần lượt là  ')' '}' ']' . Yêu cầu in ra tất cả các trường hợp là biểu thức ngoặc đúng khi thay kí tự dấu hỏi bằng các loại ngoặc đóng hoặc các loại ngoặc mở dưới dạng các con số tương ứng.
Ví dụ 1 0 0 4 ứng với ( ? ? ) sẽ in ra 1144 1254 1364 1414 ứng với (()) ({}) ([]) ()().
Input
Dòng 1: ghi số nguyên dương n (1 <= n <= 100)
Dòng 2: ghi các số nguyên dương a
Output
Ghi ra dãy các biểu thức ngoặc đúng*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 10000

int n, dp[maxlen][maxlen] = {0}, trace[maxlen], a[maxlen];
int stack[maxlen], top = 0;

void try(){
    dp[n+1][0] = 1;
    for(int i=n; i>=1; i--){
        for(int bal = 0; bal <= n; bal++){
            if(bal < n && (a[i] == 1 || a[i] == 2 || a[i] == 3)) dp[i][bal] = dp[i+1][bal+1];
            if(bal > 0 && (a[i] == 4 || a[i] == 5 || a[i] == 6)) dp[i][bal] = dp[i+1][bal-1];
            if(a[i] == 0){
                if(bal < n && dp[i+1][bal+1] == 1) dp[i][bal] = 1;
                if(bal > 0 && dp[i+1][bal-1] == 1) dp[i][bal] = 1;
            }
        }
    }
}

int match(int a, int b){
    if(a == 1 && b == 4) return 1;
    if(a == 2 && b == 5) return 1;
    if(a == 3 && b == 6) return 1;
    return 0;
}

void backtrack(int i, int bal){
    if(i > n){
        for(int j=1; j<=n; j++) printf("%d", trace[j]);
        printf(" ");
        return;
    }
    if(bal < n && dp[i+1][bal+1] == 1){
        if(a[i] != 0){
            trace[i] = a[i];
            stack[top++] = a[i];
            backtrack(i+1, bal+1);
            top--;
        }
        else{
            for(int j=1; j<=3; j++){
                trace[i] = j;
                stack[top++] = j;
                backtrack(i+1, bal+1);
                top--;
            }
        }
    }
    if(bal > 0 && dp[i+1][bal-1] == 1){
        if(a[i] != 0){
            if(match(stack[top-1], a[i]) == 0) return;
            trace[i] = a[i];
            int temp = stack[--top];
            backtrack(i+1, bal-1);
            stack[top++] = temp;
        }
        else{
            for(int j=4; j<=6; j++){
                if(match(stack[top-1], j) == 0) continue;
                trace[i] = j;
                int temp = stack[--top];
                backtrack(i+1, bal-1);
                stack[top++] = temp;
            }
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    try();
    backtrack(1, 0);
    printf("\n");
}