/*Bài 2: (3đ) Cho một văn bản gồm nhiều dòng, mỗi dòng gồm nhiều từ. Một từ được định nghĩa là một chuỗi các ký tự liên tiếp chỉ gồm các chữ cái (hoa hoặc thường). Chữ cái hoa hay chữ cái thường được xem là như nhau, ví dụ, từ "Vinh" và "vinh" hay "VINH" đều được tính là một từ. Giữa các từ có thể có một hoặc nhiều ký tự khác không phải là chữ cái, ví dụ: phẩy, chấm phẩy, hỏi chấm, dấu cách,...
Hãy viết một chương trình C in ra toàn bộ các từ trong văn bản trên kèm theo số lần xuất hiện của từ đó trong văn bản.
Dữ liệu vào: là một văn bản như mô tả ở trên chứa không quá 300 từ (chú ý là không có dấu hiệu kết thúc văn bản).
Dữ liệu ra: gồm nhiều dòng, mỗi dòng gồm có 1 từ (toàn bộ là chữ cái thường) và 1 số nguyên (số lần xuất hiện của từ đó trong văn bản) cách nhau bởi dấu cách. Các từ cần được in ra theo thứ tự alphabet.
INPUT:
Mot mau xanh, xanh. Cham them vang, vang. Mot mau xanh, cham them vang. Canh dong hoang vu.
OUTPUT:
canh 1
cham 2
dong 1
hoang 1
mau 2
mot 2
them 2
vang 3
vu 1
xanh 3*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 100000

typedef struct word{
    char word[100];
    int count;
} word;

word list[maxlen];
int wordCount = 0;

void addWord(char *word){
    for(int i=0; i<=wordCount; i++){
        if(strcmp(list[i].word, word) == 0){
            list[i].count++;
            return;
        }
    }
    strcpy(list[wordCount].word, word);
    list[wordCount].count = 1;
    wordCount++;
}

int cmp(void const* ptr1, void const* ptr2){
    word* x = (word*)ptr1;
    word* y = (word*)ptr2;
    return strcmp(x->word, y->word);
}

void printlist(){
    for(int i=0; i<wordCount; i++){
        printf("%s %d\n", list[i].word, list[i].count);
    }
}

int main(){
    char s[maxlen];
    while(fgets(s, sizeof(s), stdin)){
        s[strcspn(s, "\n\r")] = '\0';
        // if(strcmp(s, "#") == 0) break;
        char temp[100];
        int index = 0;
        for(int i=0; i<strlen(s); i++){
            if(isalpha(s[i])){
                temp[index++] = tolower(s[i]);
            }
            else{
                if(index != 0){
                    temp[index] = '\0';
                    addWord(temp);
                    index = 0;
                }
            }
        }
    }
    qsort(list, wordCount, sizeof(word), cmp);
    printlist();
}