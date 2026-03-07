/*Bài 4: (2.5đ) Một kỳ thi tuyển sinh có tối đa 100000 thí sinh tham dự. Mỗi thí sinh có 2 thông tin:
code: là mã thí sinh (xâu ký tự, có độ dài tối đa là 8 ký tự, không có thí sinh nào trùng mã với nhau)
score: điểm số (số nguyên từ 0 đến 100000, giả sử không có hai thí sinh bất kỳ nào bằng điểm nhau)
Kỳ thi này cần chọn lấy n thí sinh có điểm số cao nhất từ trên xuống.
Hãy viết chương trình C hiển thị ra màn hình thông tin code và score của n thí sinh đó.
Dữ liệu đầu vào:
Dòng đầu chứa số tự nhiên n là số thí sinh có điểm cao nhất cần hiển thị.
Các dòng tiếp theo, mỗi dòng chứa 2 thông tin là code và score của từng thí sinh, cách nhau bởi phím cách.
Dữ liệu đầu vào kết thúc bởi dòng chứa #
Kết quả đầu ra:
Hiển thị thông tin n thí sinh có điểm cao nhất cuộc thi, mỗi thí sinh trên một dòng, code và score cách nhau bởi phím cách, lần lượt từ thí sinh có điểm cao nhất đến thấp dần.
INPUT:
3
20235883 23567
20235887 25671
20235889 33456
20235893 72193
20235899 66128
20235895 55231
#
OUTPUT:
20235893 72193
20235899 66128
20235895 55231
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 100000
typedef struct data
{
    int code;
    int score;
} data;

int cmp(void const* ptr1, void const* ptr2){
    data* x = (data*)ptr1;
    data* y = (data*)ptr2;
    return y->score - x->score;
}

int main(){
    int n, k = 0;
    scanf("%d", &n);
    char c[maxlen];
    data list[maxlen];
    while(1){
        scanf("%s", c);
        if(strcmp(c, "#") == 0) break;
        list[k].code = atoi(c);
        scanf("%d", &list[k++].score);
    }
    qsort(list, k, sizeof(data), cmp);
    for(int i=0; i<n; i++) printf("%d %d\n", list[i].code, list[i].score);
}