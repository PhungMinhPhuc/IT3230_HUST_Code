/*Perform a sequence of operations over a queue, each element is an integer:
PUSH v: push a value v into the queue
POP: remove an element out of the queue and print this element to stdout (print NULL if the queue is empty)
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
1
2
3*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 10000

int main(){
    int n = 0, cntpop = 0;
    int queue[maxlen];
    char c[10];
    while(1){
        if(!fgets(c, sizeof(c), stdin)) break;
        c[strcspn(c, "\n\r")] = '\0';
        if(strcmp(c, "#") == 0) break;
        if(strncmp(c, "PUSH ", 5) == 0){
            int x;
            sscanf(c+5, "%d", &x);
            queue[n] = x;
            n++;
        }
        else if(strcmp(c, "POP") == 0){
            if(cntpop < n){
                printf("%d\n", queue[cntpop]);
                cntpop++;
            } 
            else printf("NULL\n");
        }
    }
}