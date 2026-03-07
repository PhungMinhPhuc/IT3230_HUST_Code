/*Nhập vào mảng gồm n số nguyên. Tính tổng các số chia hết cho 3 trong mảng.
Dữ liệu vào gồm 2 dòng:
- Dòng thứ nhất gồm một số nguyên là số phần tử trong mảng n (1 <= n <= 100).
- Dòng thứ hai gồm n số nguyên tương ứng với n phần tử của mảng. Hai số liên tiếp cách nhau một khoảng trắng.
Kết quả hiển thị:
Nếu n < 1 hoặc n > 100 thì hiển thị ra màn hình INVALID.
Còn ngược lại, hiển thị ra tổng các số chia hết cho 3 trong mảng. Trong trường hợp không có số nào chia hết cho 3 thì tổng sẽ bằng 0.
INPUT:
0
1
OUTPUT:
INVALID
INPUT:
5
5 3 17 32 18
OUTPUT:
21
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 10000

int main(){
    int n, sum = 0;
    scanf("%d", &n);
    int a[maxlen];
    if(n < 1 || n > 100){
        printf("INVALID\n");
        return 0;
    }
    else{
        for(int i=0; i<n; i++){
            scanf("%d", &a[i]);
            if(a[i] % 3 == 0) sum += a[i];
        }
        printf("%d\n", sum);
    }
    return 0;
}