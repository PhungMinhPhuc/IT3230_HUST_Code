/*Một bãi mìn kích thước MxN được mô tả bằng một ma trận 2 chiều kích thước MxN chứa các giá trị 1 và 0.
Trong đó 0 thể hiện một ô có mìn còn 1 là ô an toàn.
Một người cần đi từ một ô bất kỳ bên cạnh trái sang một ô bất kỳ ở cạnh phải.
Khi đi người đó chỉ được di chuyển sang các ô liền kề trên, dưới, trái, phải nhưng ô đó phải không chứa mìn và cũng không nằm cạnh ô chứa mìn.
Hãy tìm đường đi ngắn nhất.
Input: 
- Dòng đầu chứa 2 số M và N cách nhau bởi dấu cách
- M dòng sau mỗi dòng chứa N số 0 hoặc 1 cách nhau bởi dấu cách
Output:
Độ dài đường đi (là số lần di chuyển giữa 2 ô trên đường đi) hoặc -1 nếu không thể đi được

Ví dụ:
3 3
1 1 0 
1 1 1
1 1 1
Kết quả sẽ là 2
3 3
1 1 0 
1 0 1
1 1 1
Kết quả sẽ là -1*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define maxlen 10000

