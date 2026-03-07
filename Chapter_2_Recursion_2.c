/*Cho một xâu ký tự S, một xâu con của S được định nghĩa là một xâu gồm một hoặc nhiều ký tự liên tiếp của S.
Hãy viết chương trình đếm số xâu con của S có cùng ký tự bắt đầu và kết thúc.
Ví dụ xâu "abcab" có 7 xâu con thỏa mãn: a, abca, b, bcab, c, a và b*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define maxlen 10000

int main(){
    char s[maxlen];
    scanf("%s", s);
    int slen = strlen(s), count = slen;
    for(int i=0; i<slen; i++){
        for(int j=i+1; j<slen; j++){
            if(s[i] == s[j]) count ++;
        }
    }
    printf("%d", count);
}