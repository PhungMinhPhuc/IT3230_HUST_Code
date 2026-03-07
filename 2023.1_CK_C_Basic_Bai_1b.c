/*Bài 1b: (Tiếp nối bài 1a) Cứ mỗi lần đo, bác nông dân sẽ xác định con bò có sản lượng sữa lớn nhất theo số liệu có được tính tới lần đo đó, và treo ảnh con bò này lên để tuyên dương (nếu có nhiều hơn 1 con bò có cùng sản lượng sữa lớn nhất, thì sẽ treo ảnh tất cả các con bò này). Biết rằng, trước lần đo đầu tiên không có con bò nào đang được treo ảnh. Hãy giúp bác nông dân xác định xem từ lần đo đầu tiên đến lần đo cuối cùng có bao nhiêu lần phải cập nhật ảnh bò (chú ý, nếu trong 1 lần mà có nhiều hơn 1 con bò phải thay ảnh thì vẫn chỉ tính là 1 lần phải cập nhật ảnh).
Trong ví dụ trên: Ban đầu giả sử cả 3 bò đều có sản lượng 7, ngày 1 bác nông dân xác định bò Jersey có sản lượng tăng 2 so với số liệu cũ (tức là thành 9), do đó ngày 1 sẽ treo ảnh bò Jersey. Ngày 4, xác định bò Vang có sản lượng giảm 1 so với trước đó (tức là thành 6), do vậy ở ngày 4 không thay ảnh bò (vì Jersey vẫn cho sản lượng cao nhất). Ngày 7, bác nông dân xác định bò Sind có sản lượng tăng 3 (thành 10), do đó thay ảnh bò Jersey đang treo thành bò Sind. Ngày 9, bò Sind có sản lượng giảm 1 (thành 9), do đó sẽ treo lại ảnh bò Jersey (do cùng có sản lượng 9). Như vậy toàn bộ quá trình, bác nông dân đã phải cập nhật ảnh tổng cộng 3 lần.
Đầu ra gồm một số nguyên là số lần phải cập nhật ảnh bò, trong ví dụ trên là 3.
INPUT:
4
7 Sind 3
4 Vang -1
9 Sind -1
1 Jersey 2
OUTPUT:
3
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 100000

typedef struct data{
    int date;
    char name[10];
    int change;
} data;

int max(int a, int b){
    if(a > b) return a;
    else return b;
}

int cmp(void const* ptr1, void const* ptr2){
    data* x = (data*)ptr1;
    data* y = (data*)ptr2;
    return x->date - y->date;
}

int main(){
    int n;
    scanf("%d", &n);
    data a[maxlen];
    int display = 0, ChangeS = 0, ChangeV = 0, ChangeJ = 0, count = 0;
    for(int i=0; i<n; i++){
        scanf("%d %s %d", &a[i].date, a[i].name, &a[i].change);
    }
    qsort(a, n, sizeof(data), cmp);
    for(int i=0; i<n; i++){
        if(strcmp(a[i].name, "Sind") == 0)  ChangeS += a[i].change;
        else if(strcmp(a[i].name, "Vang") == 0) ChangeV += a[i].change;
        else if(strcmp(a[i].name, "Jersey") == 0) ChangeJ += a[i].change;
        int newdisplay = 0;
        int curMax = max(max(ChangeJ, ChangeS), ChangeV);
        if(curMax == ChangeJ) newdisplay |= 1;
        if(curMax == ChangeS) newdisplay |= 2;
        if(curMax == ChangeV) newdisplay |= 3;
        if(newdisplay != display){
            count++;
            display = newdisplay;
        }
    }
    printf("%d\n", count);
    // for(int i=0; i<n; i++) printf("%d %s %d\n", a[i].date, a[i].name, a[i].change);
}