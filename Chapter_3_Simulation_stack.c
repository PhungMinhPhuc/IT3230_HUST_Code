/*Perform a sequence of operations over a stack, each element is an integer:
PUSH v: push a value v into the stack
POP: remove an element out of the stack and print this element to stdout (print NULL if the stack is empty)
Input
Each line contains a command (operration) of type 
PUSH  v
POP
Output
Write the results of POP operations (each result is written in a line)
Example
Input
PUSH 1
PUSH 2
PUSH 3
POP
POP
PUSH 4
PUSH 5
POP
#
Output
3
2
5*/

//Cách 1: Stack dùng mảng
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define maxlen 10000

int main(){
    int stack[maxlen], n = 0;
    int cntpop = 0;
    char c[10];
    while(1){
        if(!fgets(c, sizeof(c), stdin)) break;
        c[strcspn(c, "\n\r")] = '\0';
        if(strcmp(c, "#") == 0) break;
        if(strncmp(c, "PUSH ", 5) == 0){
            int m;
            sscanf(c+5, "%d", &m);
            stack[n] = m;
            n++;
        }
        else if(strcmp(c, "POP") == 0){
            if(n>0){
                printf("%d\n", stack[--n]);
                cntpop++;
            }
            else {
                printf("NULL\n");
            } 
        }
    }
}

//Cách 2: Stack dùng linked list