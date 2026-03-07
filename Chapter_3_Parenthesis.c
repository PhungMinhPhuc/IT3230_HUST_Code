/*Given a string containing only characters (, ), [, ] {, }. Write a program that check whether the string is correct in expression. 
Example:
([]{()}()[]): correct
([]{()]()[]): incorrect
Input
One line contains the string (the length of the string is less than or equal to 10^6)
Output
Write 1 if the sequence is correct, and write 0, otherwise
Example:
input
(()[][]{}){}{}[][]({[]()})
output
1*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 100000

int match(char a, char b){
    if(a == '(' && b == ')') return 1;
    if(a == '[' && b == ']') return 1;
    if(a == '{' && b == '}') return 1;
    return 0;
}

int main(){
    int n = 0, m = 0;
    char a[maxlen], stack[maxlen];
    fgets(a, sizeof(a), stdin);
    a[strcspn(a, "\n\r")] = '\0';
    for(int i=0; i<strlen(a); i++){
        if(a[i] == '(' || a[i] == '[' || a[i] == '{'){
            stack[n] = a[i];
            n++;
        }
        else{
            if(n <= 0 || (n > 0 && match(stack[--n], a[i]) == 0)){
                printf("0\n");
                return 0;
            }
        }
    }
    if(n == 0) printf("1\n");
    else printf("0\n");
}