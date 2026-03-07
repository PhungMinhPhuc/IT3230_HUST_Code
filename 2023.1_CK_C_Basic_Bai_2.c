/*Bài 2: Ở một quốc gia có n loại tiền gồm các mệnh giá a1, a2, ..., an (n ≤ 10). Đương nhiên, các mệnh giá này không trùng giá trị với nhau, tức là ai ≠ aj, ∀ i ≠ j. Có bao nhiêu cách để chọn ra một số tiền để được tổng mệnh giá là S, biết rằng mỗi mệnh giá tiền có thể được lấy nhiều lần và hai cách lấy là hoán vị của nhau chỉ được tính là 1.
Ví dụ, với 3 loại tiền mệnh giá 10, 20, 50 thì có 10 cách lấy để có tổng mệnh giá là 100: 10 tờ 10; 2 tờ 50; 3 tờ 10, 1 tờ 20, 1 tờ 50; ...
Trong ví dụ trên, cách lấy 3 tờ 10, 1 tờ 20, 1 tờ 50 được tính như là cách lấy 1 tờ 50, 3 tờ 10, 1 tờ 20 vì chúng chỉ là hoán vị của nhau.
Ví dụ minh họa:
INPUT:
3 100
10 20 50
OUTPUT:
10
Giải thích: Đầu vào gồm 2 dòng: dòng 1 là 2 số nguyên dương n (≤ 10) và S (≤ 1000) cách nhau bởi phím cách; dòng 2 là n số nguyên dương a1, a2, ..., an phân cách nhau bởi phím cách (ai ≤ 1000).
Đầu ra gồm 1 số nguyên không âm duy nhất là số cách lấy (là 0 nếu không có cách lấy nào thỏa mãn). Ví dụ đầu ra mẫu cho đầu vào mẫu ở trên có 10 cách chọn là:
(1) 10 tờ mệnh giá 10
(2) 8 tờ mệnh giá 10 và 1 tờ mệnh giá 20
(3) 6 tờ mệnh giá 10, 2 tờ mệnh giá 20
(4) 5 tờ mệnh giá 10, 1 tờ mệnh giá 50
(5) 4 tờ mệnh giá 10, 3 tờ mệnh giá 20
(6) 3 tờ mệnh giá 10, 1 tờ mệnh giá 20 và 1 tờ mệnh giá 50
(7) 2 tờ mệnh giá 10, 4 tờ mệnh giá 20
(8) 1 tờ mệnh giá 10, 2 tờ mệnh giá 20 và 1 tờ mệnh giá 50
(9) 5 tờ mệnh giá 20
(10) 2 tờ mệnh giá 50
Do đó kết quả ra sẽ là 10.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 101

int main(){
    int n, s;
    scanf("%d %d", &n, &s);
    int coins[maxlen];
    for(int i=0; i<n; i++) scanf("%d", &coins[i]);
    int dp[maxlen] = {0};
    dp[0] = 1;
    for(int i=0; i<n; i++){
        for(int j=coins[i]; j<=s; j++){
            dp[j] += dp[j-coins[i]];
        }
    }
    printf("%d\n", dp[s]);
}