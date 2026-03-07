/*Cho xâu S có N < 120000 ký tự chữ số. Hãy xóa đi K (K < N) ký tự để xâu còn lại biểu diễn một số bé nhất (số có thể bắt đầu bằng chữ số 0). Đầu vào có dòng 1 chứa xâu độ dài tối đa. Dòng 2 chứa K. Đầu ra là xâu sau khi xóa.
Ví dụ
Input:
869357495356872
9
Output:
335672*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 120000

int main(){
    int k, m = 0;
    char a[maxlen], stack[maxlen];
    scanf("%s %d", a, &k);
    for(int i=0; i<strlen(a); i++){
        while(a[i] < stack[m-1] && k>0 && m>0){
            m--;
            k--;
        }
        stack[m++] = a[i];
    }
    if(k>0) m -= k;
    for(int i=0; i<m; i++) printf("%c", stack[i]);
}