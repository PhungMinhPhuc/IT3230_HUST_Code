/*Viết chương trình nhập vào một xâu ký tự và hiển thị số lần xuất hiện của mỗi ký tự có trong xâu. 

Kết quả hiển thị với xâu đầu vào:  "hello, world!"

The letter 'd' appears 1 time(s).
The letter 'e' appears 1 time(s).
The letter 'h' appears 1 time(s).
The letter 'l' appears 3 time(s).
The letter 'o' appears 2 time(s).
The letter 'r' appears 1 time(s).
The letter 'w' appears 1 time(s).

Lưu ý: Chỉ xét các ký tự chữ cái thường trong xâu, các ký tự khác bỏ qua!
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define maxlen 10000

int main(){
    char s[maxlen];
    int count[maxlen] = {0};
    fgets(s, sizeof(s), stdin);
    int slen = strlen(s);
    for(int i=0; i<slen; i++){
        count[s[i]] ++;
    }
    for(int i=97; i<(97+26); i++){
        if(count[i] > 0) printf("The letter '%c' appears %d time(s).\n", i, count[i]);
    }
}