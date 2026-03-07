/*Bài 3: (2.5đ) Thầy Hiếu rất nổi tiếng trong cộng đồng Aikido nên câu lạc bộ của thầy thường có nhiều bạn đăng kí học (tối thiểu 0 bạn, tối đa có thể lên đến 4000 bạn). Lần đăng kí này thầy cho các bạn đăng kí xếp thành hai hàng, một bên là nam, một bên là nữ.
Mỗi khi có một bạn nữ đến sẽ xếp vào cuối hàng nữ, có một bạn nam đến sẽ xếp vào cuối hàng nam. Tại một thời điểm sẽ có một bạn nam hoặc nữ ở đầu hàng đăng kí vào lớp và tên của bạn sẽ được hiển thị trên bảng điện tử chào mừng.
Lưu ý, do các tên đẹp được nhiều bố mẹ chọn nên tên các bạn có thể trùng nhau.
Input: nhận một trong các lệnh sau:
ENQUEUE X V: Xếp bạn V (xâu kí tự không chứa dấu cách có tối đa 20 kí tự) vào cuối hàng X (nhận một trong hai giá trị 0 (nam) và 1 (nữ))
DEQUEUE X: Đăng kí bạn đầu hàng X vào lớp và hiển thị tên ra stdout cùng với lời chào mừng "Welcome tên" (nếu hàng đã hết thì hiển thị NULL)
#: Kết thúc chương trình
Ví dụ:
INPUT:
ENQUEUE 0 Long
ENQUEUE 0 Hoang
ENQUEUE 1 Hoa
DEQUEUE 0
DEQUEUE 1
DEQUEUE 1
ENQUEUE 0 Quyet
#
OUTPUT:
Welcome Long
Welcome Hoa
NULL
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 10000

typedef struct queue{
    char name[100];
} queue;

int main(){
    queue men[maxlen], women[maxlen];
    int mleft = 0, mright = 0, wleft = 0, wright = 0;
    char c[maxlen];
    while(1){
        scanf("%s", c);
        if(strcmp(c, "#") == 0) break;
        else if(strcmp(c, "ENQUEUE") == 0){
            int sex;
            char name[100];
            scanf("%d %s", &sex, name);
            if(sex == 0) strcpy(men[mright++].name, name);
            else strcpy(women[wright++].name, name);
        }
        else if(strcmp(c, "DEQUEUE") == 0){
            int sex;
            scanf("%d", &sex);
            if(sex == 0 && mleft < mright) printf("Welcome %s\n", men[mleft++].name);
            else if(sex == 1 && wleft < wright) printf("Welcome %s\n", women[wleft++].name);
            else printf("NULL\n");
        }
    }
}