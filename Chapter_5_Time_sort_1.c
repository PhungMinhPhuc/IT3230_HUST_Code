/*Một cửa hàng nọ đang có kế hoạch tuyển nhân công trả tiền theo giờ làm việc. Mỗi người đến xin việc sẽ ghi lại thời điểm bắt đầu và thời điểm kết thúc giờ làm của họ. Tính đến thời điểm hiện tại, đã có 𝑛 hồ sơ xin việc, người thứ 𝑖 đăng kí thời điểm bắt đầu làm việc 𝑎(𝑖) và thời điểm kết thúc làm việc 𝑏(𝑖).
Nếu tuyển cả 𝑛 người vào làm việc, tính từ thời điểm bắt đầu của người làm việc sớm nhất đến thời điểm kết thúc làm việc của người làm việc muộn nhất, ông chủ muốn biết: khoảng thời gian dài nhất luôn có ít nhất một người làm việc.
Ví dụ: có 5 người xin việc, với thời gian đăng kí giờ làm lần lượt là [3, 8], [2, 5], [9, 12], [19, 24], [1, 4] thì khoảng thời gian dài nhất luôn có ít nhất 1 người làm là 7 (từ thời điểm 1 đến hết thời điểm 7 còn từ khi bắt đầu thời điểm 8 là đã không có ai làm).
Dữ liệu:
• Dòng đầu ghi số 𝑛 (𝑛 ≤ 5000): số người xin việc.
• 𝑛 dòng tiếp theo, dòng thứ 𝑖 gồm 2 số 𝑎(𝑖) và (0 ≤ 𝑎(𝑖) ≤ 𝑏(𝑖)≤ 10000000): thời điểm bắt đầu và kết thúc làm việc của người thứ 𝑖.
Kết quả: 1 số nguyên 𝑚 là khoảng thời gian luôn có người làm.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 10000

typedef struct data{
    int start;
    int end;
} data;

void swap(data *a, data *b){
    data temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int i, data *a, int n){
    int largest = i, left = 2*i+1, right = 2*i+2;
    if(left < n && a[largest].start < a[left].start) largest = left;
    if(right < n && a[largest].start < a[right].start) largest = right;
    if(largest != i){
        swap(&a[largest], &a[i]);
        heapify(largest, a, n);
    }
}

void heapsort(data *a, int n){
    for(int i=n/2-1; i>=0; i--) heapify(i, a, n);
    for(int i=n-1; i>0; i--){
        swap(&a[0], &a[i]);
        heapify(0, a, i);
    }
}

int main(){
    data worker[maxlen];
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &worker[i].start, &worker[i].end);
    }
    heapsort(worker, n);
    int left = worker[0].start, right = worker[0].end, m = 0;
    for(int i=1; i<n; i++){
        if(right < worker[i].start){
            if(m < right - left) m = right - left;
            left = worker[i].start;
            right = worker[i].end;
        }
        else{
            if(right < worker[i].end) right = worker[i].end;
        }
    }
    if(m < right - left) m = right - left;
    printf("%d\n", m);
    // for(int i=0; i<n; i++){
    //     printf("%d %d\n", worker[i].start, worker[i].end);
    // }
}