/*Bài 1a: Bác nông dân nuôi 3 con bò sữa (tạm gọi tên là Sind, Vang, và Jersey). Ban đầu mỗi con bò đều cùng một lượng sữa mỗi ngày. Tuy nhiên, sản lượng sữa bò thay đổi theo thời gian nên bác nông dân thực hiện các phép đo trong N lần (1 ≤ N ≤ 100). Vì nhiều việc quá nên mỗi ngày bác nông dân chỉ làm được 1 phép đo với 1 con bò và ghi lại kết quả ở dạng sau:
D Name Change
• D là một số nguyên ∈ [0, 365], là ngày thực hiện phép đo  
• Name là tên con bò được đo (chỉ nhận một trong 3 giá trị ở trên)  
• Change là một số nguyên ∈ [-10, 10], là sản lượng sữa thay đổi so với lần đo gần nhất trước đó.
Cũng do lớn tuổi, nên bác nông dân ghi kết quả hơi lộn xộn: các dòng không theo thứ tự thời gian. Hãy giúp xác định sản lượng sữa tăng nhiều
nhất của một con bò (hoặc giảm ít nhất nếu không có con bò nào tăng sản lượng) sau khi kết thúc quá trình đo đã thực hiện.
INPUT:
4
7 Sind 3
4 Vang -1
9 Sind -1
1 Jersey 2
OUTPUT:
2
Giải thích: Đầu vào gồm có 1 số nguyên ở dòng đầu tiên là số lần đo N, sau đó có N dòng tiếp theo, mỗi dòng là kết quả của một lần đo. D, Name, Change
phân cách nhau bởi phím space.
Đầu ra là 1 con số (nguyên không âm) duy nhất thể hiện sản lượng tăng nhiều nhất (hoặc giảm ít nhất). Trong ví dụ trên, bò Jersey (tăng 2 ở
ngày 1) và bò Sind (tăng 3 ở ngày 7 nhưng giảm 1 ở ngày 9) nên đều có sản lượng tăng 2 sau khi kết thúc quá trình đo. Vì thế đầu ra sẽ là: 2
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

int main(){
    int n;
    scanf("%d", &n);
    data a[maxlen];
    int totalChangeS = 0, totalChangeV = 0, totalChangeJ = 0;
    for(int i=0; i<n; i++){
        scanf("%d %s %d", &a[i].date, a[i].name, &a[i].change);
        if(strcmp(a[i].name, "Sind") == 0) totalChangeS += a[i].change;
        if(strcmp(a[i].name, "Vang") == 0) totalChangeV += a[i].change;
        if(strcmp(a[i].name, "Jersey") == 0) totalChangeJ += a[i].change;
    }
    printf("%d\n", max(max(totalChangeS, totalChangeV), totalChangeJ));
}