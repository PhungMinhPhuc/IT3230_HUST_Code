/*Cần thống kê xem mỗi ngày có bao nhiêu lượt sinh viên làm trắc nghiệm.
Input
Thông tin về sinh viên làm trắc nghiệm ôn tập được cho theo các dòng định dạng như sau:
<yyyy-mm-dd> <hh:mm:ss> <user_id> <question_id>: trong đó sinh viên có mã <user_id> làm câu hỏi <question_id> vào ngày giờ là <yyyy-mm-dd> <hh:mm:ss>
Kết thúc dữ liệu là 1 dòng chứa dấu *
Output
Mỗi dòng ghi <yyyy-mm-dd> <cnt>: trong đó <cnt> là số lượt sinh viên làm trắc nghiệm trong ngày <yyyy-mm-dd>
(chú ý: các dòng được sắp xếp theo thứ tự tăng dần của ngày thống kê, ngày thống kê nào mà không có lượt sinh viên làm trắc nghiệm thì không in ra)
Example
Input
2022-01-02 10:30:24 dungpq question1
2022-01-03 11:30:24 dungpq question1
2022-02-01 03:30:20 viettq question2
2022-02-01 03:35:20 viettq question1
2022-03-01 03:30:20 viettq question7
2022-01-02 11:20:24 viettq question2
*
Output
2022-01-02 2
2022-01-03 1
2022-02-01 2
2022-03-01 1*/

/*Cách 1: Chẳng biết nhưng bị lỗi bộ nhớ, time (O(n^2))*/
/*
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define maxlen 100000

typedef struct {
    char date[11];
    int count;
} inf;

int main(){
    int n = 0;
    char c[maxlen], date[11], rest[maxlen];
    inf a[maxlen];
    while(fgets(c, sizeof(c), stdin)){
        c[strcspn(c, "\n\r")] = '\0';
        if(strcmp(c, "*") == 0) break;
        sscanf(c, "%s %s", date, rest);
        int found = 0;
        for(int i=0; i<n; i++){
            if(strcmp(a[i].date, date) == 0){
                a[i].count ++;
                found = 1;
                break;
            }
        }
        if(found == 0){
            strcpy(a[n].date, date);
            a[n].count = 1;
            n++;
        }
    }
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(strcmp(a[i].date, a[j].date) > 0){
                inf temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for(int i=0; i<n; i++){
        printf("%s %d\n", a[i].date, a[i].count);
    }
}
*/

/*Cach 2: Dùng qsort, tốc độ cải thiện là O(nlogn)*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxlen 100000

typedef struct inf{
    char data[15];
} inf;

int cmp(const void* ptr1, const void* ptr2){
    inf* x = (inf*)ptr1;
    inf* y = (inf*)ptr2;
    return strcmp(x->data, y->data);
}

int main()
{
    int count = 1, n = 0;
    char date[15], hour[10], name[100], info[1000];
    inf a[maxlen];
    while(1){
        if(!scanf("%s", date)) break;
        if(date[0] == '*') break;
        strcpy(a[n].data, date);
        scanf("%s %s %s", &hour, &name, &info);
        n++;
    }
    qsort(a, n, sizeof(inf), cmp);
    for(int i=0; i<n; i++){
        if(i == n || strcmp(a[i].data, a[i+1].data) == 0) {
            count++;
        }
        else{
            printf("%s %d\n", a[i].data, count);
            count = 1;
        }
    }
}