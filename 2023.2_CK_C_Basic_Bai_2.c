/*Bài 2: (2đ) Bác nông dân bị lạc mất một con bò và cần phải tìm lại nó. Chỉ có một con đường dài chạy qua nông trại của bác, và con bò ở đâu đó trên con đường này. Giả sử con đường này là một đường thẳng như chiếc thước kẻ có chia vạch cách đều nhau. Vị trí tọa độ ban đầu của bác nông dân là x, của con bò là y. Lưu ý rằng, bác nông dân không biết vị trí con bò nằm ở đâu trên đường thẳng này.
Bác nông dân làm theo hướng dẫn của chuyên gia để tìm con bò, bằng cách đi "zig zag" lần lượt sang phải, rồi sang trái, rồi lại sang phải, rồi lại sang trái,… như sau: từ tọa độ ban đầu trên đường thẳng là x, di chuyển sang phải đến tọa độ x+1, rồi di chuyển ngược lại sang trái đến tọa độ x-2, rồi di chuyển sang phải đến tọa độ x+4,… đến khi tìm thấy con bò thì dừng lại.
Tức là, mỗi lần di chuyển, bác nông dân sẽ đi đến điểm theo chiều ngược lại có khoảng cách với điểm gốc ban đầu x gấp đôi so với khoảng cách từ điểm dừng trước đó đến điểm gốc ban đầu x.
Bác nông dân suy nghĩ, không biết làm theo lời chuyên gia thì quãng đường di chuyển là bao nhiêu.
Hãy giúp bác nông dân viết chương trình C, đọc từ bàn phím 2 số nguyên x, y cách nhau bởi phím cách, hiển thị quãng đường mà bác nông dân phải đi để tìm thấy con bò.
INPUT: 3 6
OUTPUT: 9
Giải thích: x=3, y=6
Ban đầu, bác nông dân ở vị trí x=3, di chuyển đến x+1=4, rồi di chuyển ngược lại vị trí x-2=1, rồi di chuyển đến vị trí x+4=7. Tuy nhiên, để đi đến 7 thì phải đi qua 6 là vị trí của con bò nên bác nông dân tìm thấy con bò ở vị trí 6 và không cần phải đi nốt đến vị trí 7 nữa. Vậy, tổng quãng đường mà bác phải di chuyển là: 1 + 3 + 5 = 9
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define maxlen 100000

int main(){
    // FILE *fin = fopen("lostcow.in", "r");
    // FILE *fout = fopen("lostcow.out", "w");
    // int x, y;
    // fscanf(fin, "%d %d", &x, &y);
    int x, y;
    scanf("%d %d", &x, &y);
    int cur = x, next, n = 0, total = 0;
    while(1){
        next = x + pow(-2, n);
        if((cur <= y && next >= y) || (cur >= y && next <= y)){
            total += abs(y - cur);
            break;
        }
        total += abs(next - cur);
        cur = next;
        n++;
    }
    printf("%d\n", total);
    // fprintf(fout, "%d\n", total);
    // fclose(fin);
    // fclose(fout);
}