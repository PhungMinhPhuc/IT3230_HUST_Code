/*A candidate of a contest has following information:
code: info of length from 2 to 10
score: integer from 0 to 1000000 (scores of candidates are distinct)

Write a program to sort the list of candidates in non-increasing order of scores.

Input
Each line contains the information of a candidate (code and score: separated by a SPACE character)
The input is terminated by a line containing #

Ouput
Write in each line the information of a candidate in the sorted list(code and score separated by a SPACE character)
 
Example
Input
S00001 27412
S00002 22981
S00003 32561
S00004 10915
S00005 17566
#

Output 
S00003 32561
S00001 27412
S00002 22981
S00005 17566
S00004 10915*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 100000

typedef struct info{
    char code[12];
    int score;
} info;

int cmpScore(void const* ptr1, void const* ptr2){
    info* x = (info*)ptr1;
    info* y = (info*)ptr2;
    return y->score - x->score;
}

int main(){
    int n = 0;
    info a[maxlen];
    while(1){
        scanf("%s", a[n].code);
        if(strcmp(a[n].code, "#") == 0) break;
        scanf("%d", &a[n].score);
        n++;
    }
    qsort(a, n, sizeof(info), cmpScore);
    for(int i=0; i<n; i++) printf("%s %d\n", a[i].code, a[i].score);
}