/*Given a string representing a math expression including operator + and * and operands which are positive integer and parentheses. Compute the value Q of this expression.
Input
Line 1: contains the string representing the expression (number of operators is upto 10000)
Output
Write the value Q modulo 10^9+7 if the expression is mathematically correct in term of the syntax, and write NOT_CORRECT, otherwise
Example
Input
(2+4*10)*(5) + 7
Output
217

Input
((2+4*10)*(5) + 7
Output
NOT_CORRECT*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MOD 1000000007LL
#define maxlen 100000

int main(){
    char c[maxlen];
    long long stackS[maxlen], stackP[maxlen];
    long long product = 1, sum = 0;
    int num = 0, i = 0;
    fgets(c, sizeof(c), stdin);
    c[strcspn(c, "\n\r")] = '\0';
    char *s = c;
    while(*s){
        if(isdigit(*s)){
            num = num*10 + (*s - '0');
        }
        else if(*s == '+'){
            product *= num;
            sum += product;
            product = 1;
            num = 0;
        }
        else if(*s == '*'){
            product *= num;
            num = 0;
        }
        else if(*s == '('){
            stackS[i] = sum;
            stackP[i] = product;
            i++;
            sum = 0;
            product = 1;
            num = 0;
        }
        else if(*s == ')'){
            product *= num;
            sum += product;
            i--;
            product = stackP[i]*sum;
            sum = stackS[i];
            //product = 1;
            num = 0;
        }
        s++;
    }
    if(i>0) printf("NOT_CORRECT");
    else printf("%lld\n", sum%MOD);
}
//C 
// #include <stdio.h> 
// #include <string.h>
// #include <ctype.h>
// #define mod 1000000007

// int main() 
// { 
//     char s[1000000];
//     long long sum = 0, product = 1;
//     fgets(s, sizeof(s), stdin);
//     long long n = strlen(s);
//     for(long long i=0; i<n; i++){
//         if((s[i]=='*' && (s[i+1]=='+' || s[i-1]=='+')) || s[0]=='*' || s[n-1]=='*') {
//             printf("NOT_CORRECT");
//             return 0;
//         }
//     }
//     long long i=0;
//     while(i < n){
//         long long num=0;
//         while(isdigit(s[i])) {
//             num = num*10 + (s[i] - '0');
//             i++;
//         }
//         if(s[i]=='*') {
//             product *= num;
//             i++;
//         }
//         else{
//             product *= num;
//             sum += product;
//             product = 1;
//             i++;
//         }
//     }
//     printf("%lld", sum%mod);
// }
