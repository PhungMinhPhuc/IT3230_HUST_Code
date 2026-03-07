/*Cho một từ điển gồm một tập các từ, mỗi từ chỉ gồm các chữ cái viết liên tiếp. Độ dài 1 từ không quá 16 ký tự.
Cho một chuỗi ký tự chỉ gồm các chữ cái viết liên tiếp (không quá 100 ký tự). 
Hãy tìm cách trả lời xem chuỗi này có thể tách thành một chuỗi các từ có trong từ điển không?
In ra Yes nếu có và No nếu không
INPUT:
- Dòng đầu chứa chuỗi cần xử lý
- Các dòng sau mỗi dòng chứa 1 từ của từ điển
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 100

typedef struct dict{
    char w[18];
} dict;

char s[102], c[20];
int n = 0;
int memo[102], memolen;

int try(int k, dict dic[]){
    if(k<0) return 1;
    if(memo[k] != -1) return memo[k];
    for(int i=0; i<n; i++){
        int wordlen = strlen(dic[i].w);
        if((k - wordlen + 1) < 0) continue;
        if((strncmp(dic[i].w, s + k - wordlen + 1, wordlen) == 0) && try(k - wordlen, dic)){
            memo[k] = 1;
            return 1;
        }
    }
    memo[k] = 0;
    return 0;
}

int main(){
    dict dic[maxlen];
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n\r")] = '\0';
    while(1){
        if(!fgets(c, sizeof(c), stdin)) break;
        c[strcspn(c, "\n\r")] = '\0';
        if(strlen(c) == 0) break; 
        strcpy(dic[n].w, c);
        n++;
    }
    memolen = strlen(s);
    memset(memo, -1, sizeof(memo));
    if(try(memolen - 1, dic)) printf("Yes\n");
    else printf("No\n");
}