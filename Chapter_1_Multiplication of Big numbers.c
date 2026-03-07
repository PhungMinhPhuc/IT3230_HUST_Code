/*Multiplication of Big numbers
Cho hai số nguyên dương a và b rất lớn (số chữ số có thể lên tới 10000). Hãy tính và in ra tích của 2 số đó.
Input
Dòng 1: ghi số a
Dòng 2: ghi số b
Output
Ghi kết quả a*b

Example
Input
100000000000000000
123456789
Output
12345678900000000000000000*/

/*Giải thuật:
Đọc hai chuỗi a, b.
Đảo ngược hai chuỗi (để thuận tiện nhân từ hàng đơn vị).
Tạo mảng c[] có kích thước đủ lớn, ban đầu gán toàn 0.
Với từng chữ số a[i], nhân với từng chữ số b[j], rồi cộng vào res[i + j].
Sau khi nhân xong, xử lý nhớ (carry) cho từng phần tử của res.
Bỏ các số 0 dư ở đầu, rồi in kết quả ngược lại.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 100000

// int main(){
//     char a[maxlen], b[maxlen];
//     int c[maxlen] = {0};
//     fgets(a, sizeof(a), stdin);
//     a[strcspn(a, "\n\r")] = '\0';
//     int m = strlen(a);
//     fgets(b, sizeof(b), stdin);
//     b[strcspn(b, "\n\r")] = '\0';
//     int n = strlen(b);
//     for(int i=0; i<m/2; i++){
//         char temp = a[i];
//         a[i] = a[m-1-i];
//         a[m-1-i] = temp;
//     }
//     for(int i=0; i<n/2; i++){
//         char temp = b[i];
//         b[i] = b[n-1-i];
//         b[n-1-i] = temp;
//     }
//     for(int i=0; i<m; i++){
//         for(int j=0; j<n; j++){
//             c[i+j] += (a[i] - '0') * (b[j] - '0');
//         }
//     }
//     for(int i=0; i<n+m; i++){
//         c[i+1] += c[i]/10;
//         c[i] = c[i]%10;
//     }
//     int i = m+n;
//     while(i>0 && c[i] == 0) i--;
//     for(; i>=0; i--){
//         printf("%d", c[i]);
//     }
// }

int main(){
    char a[maxlen], b[maxlen];
    int c[maxlen] = {0};
    fgets(a, sizeof(a), stdin);
    a[strcspn(a, "\n\r")] = '\0';
    fgets(b, sizeof(b), stdin);
    b[strcspn(b, "\n\r")] = '\0';
    int m = strlen(a), n = strlen(b);
    for(int i=m-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            c[i+j+1] += (a[i] - '0')*(b[j] - '0');
        }
    }
    for(int i=m+n-1; i>0; i--){
        c[i-1] += c[i]/10;
        c[i] = c[i]%10;
    }
    int i = 0;
    while(i<m+n-1 && c[i] == 0) i++;
    for(; i<n+m; i++) printf("%d", c[i]);
}