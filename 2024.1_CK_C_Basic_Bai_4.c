/*Bài 4: (2đ) Trung tâm NAVIS đang phát triển một hệ thống hiển thị các xe trên bản đồ số. Vị trí mỗi xe được cho bởi một tọa độ gồm kinh độ và vĩ độ là các số thực, ví dụ: (x, y) = (105.84399, 20.99654). Danh sách ban đầu gồm N xe (N ≤ 50000). Khi bắt đầu chạy app, thời gian để hiện toàn bộ bản đồ và các xe trên bản đồ là rất lâu, gây khó chịu cho người dùng, do đó lập trình viên quyết định tối ưu việc hiển thị các xe trên bản đồ theo nguyên tắc: chỉ hiện các xe mà tọa độ của nó nằm trong khung nhìn của bản đồ (bỏ qua cả các điểm nằm trên biên). Khung nhìn của bản đồ là một hình chữ nhật được cho bởi cặp tọa độ (x, y) của 2 điểm trái-trên và phải-dưới. Chú ý rằng tọa độ của Việt Nam kéo dài từ vĩ độ 7 đến 30 và kinh độ 100 đến 110. Xem mô tả hướng của các trục kinh độ và vĩ độ ở hình vẽ trong đề in được phát. (Chiều tăng vĩ dộ theo trục y, kinh độ theo trục x)
Khi sử dụng ứng dụng, người dùng thường xuyên thực hiện di chuyển bản đồ, zoom-in, zoom-out làm cho khung nhìn bị thay đổi. Do đó, lập trình viên cần liên tục thực hiện thao tác kiểm tra xem những xe nào nằm trong khung nhìn để từ đó quyết định thêm hoặc bớt các xe vào danh sách hiển thị. Hãy viết chương trình C để thực hiện thao tác trên.
Dữ liệu vào:
- Dòng đầu tiên là số lượng xe N (N > 0 và N ≤ 50000), số lượng lần truy vấn M (M > 0 và M ≤ 5000)
- N dòng tiếp theo, mỗi dòng chứa 2 số thực cách nhau bởi dấu cách là tọa độ của 1 xe (theo thứ tự là kinh độ và vĩ độ nằm trong phạm vi đã mô tả ở trên)
- M dòng tiếp theo, mỗi dòng chứa 4 số thực tương ứng là tọa độ của điểm trái-trên và phải-dưới của khung nhìn
Dữ liệu ra:
Ứng với mỗi truy vấn, hãy in ra số lượng xe nằm trong khung nhìn.

INPUT:
5 3
101.23  7.34
104.57  9.32
105.65  25.54
108.26  23.12
109.18  10.77
101.12  29.44  109.33  7.14
105.45  27.12  108.45  8.99
106.55  25.01  108.22  12.29

OUTPUT:
5
2
0*/

// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// #include <stdlib.h>

// #define maxlen 10000

// typedef struct point{
//     float x;
//     float y;
// } point;

// typedef struct rectangle{
//     float x1, y1, x2, y2;
// } rectangle;

// int main(){
//     int n, m;
//     scanf("%d %d", &n, &m);
//     point p[50000];
//     rectangle r[5000];
//     for(int i=0; i<n; i++) scanf("%f %f", &p[i].x, &p[i].y);
//     for(int i=0; i<m; i++){
//         scanf("%f %f %f %f", &r[i].x1, &r[i].y1, &r[i].x2, &r[i].y2);
//         int count = 0;
//         for(int j=0; j<n; j++){
//             if(p[j].x > r[i].x1 && p[j].x < r[i].x2 && p[j].y > r[i].y2 && p[j].y < r[i].y1) count ++;
//         }
//         printf("%d\n", count);
//     }
// }

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 10000

typedef struct point{
    double x;
    double y;
} point;

typedef struct rectangle{
    double x1, y1, x2, y2;
} rectangle;

int cmp(void const* ptr1, void const* ptr2){
    point* x = (point*)ptr1;
    point* y = (point*)ptr2;
    if(x->x < y->x) return -1;
    if(x->x > y->x) return 1;
    return 0;
}

int lowerbound(point* p, int n, double target){
    int left = 0, right = n;
    while(left < right){
        int med = (left+right)/2;
        if(p[med].x < target) left = med + 1;
        else right = med;
    }
    return left;
}

int upperbound(point* p, int n, double target){
    int left = 0, right = n;
    while(left < right){
        int med = (left+right)/2;
        if(p[med].x <= target) left = med + 1;
        else right = med;
    }
    return left;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    point p[50000];
    rectangle r[5000];
    for(int i=0; i<n; i++) scanf("%lf %lf", &p[i].x, &p[i].y);
    qsort(p, n, sizeof(point), cmp);
    for(int i=0; i<m; i++){
        scanf("%lf %lf %lf %lf", &r[i].x1, &r[i].y1, &r[i].x2, &r[i].y2);
        int count = 0;
        int start = upperbound(p, n, r[i].x1);
        int end = lowerbound(p, n, r[i].x2);
        for(int j = start; j < end; j++){
            if(p[j].y > r[i].y2 && p[j].y < r[i].y1) count ++;
        }
        printf("%d\n", count);
    }
}