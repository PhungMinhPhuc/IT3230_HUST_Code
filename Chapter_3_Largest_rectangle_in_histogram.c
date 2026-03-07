/*Tìm hình chữ nhật có diện tích lớn nhất tạo bởi các cột liên tiếp của một đồ thị histogram.
Dữ liệu vào gồm:
Dòng 1: Số N là số lượng cột (N < 1000)
N dòng tiếp theo mỗi dòng là một số nguyên dương là chiều cao của cột
In ra số nguyên dương duy nhất là diện tích lớn nhất tìm được.
Input:
7
6 2 5 4 5 1 6
Output:
12
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 1000

void process(int n, int height[]) {
    int stack[maxlen];
    int maxArea = 0, top = -1;
    for (int i = 0; i <= n; i++) {
        while (top >= 0 && height[stack[top]] > height[i]) {
            int h_idx = stack[top--];
            int width;
            if (top == -1) width = i;
            else width = (i - 1) - (stack[top] + 1) + 1;
            int area = height[h_idx] * width;
            if (area > maxArea) maxArea = area;
        }
        stack[++top] = i;
    }
    printf("%d\n", maxArea);
}


int main(){
    int n;
    scanf("%d", &n);
    int height[maxlen];
    for(int i=0; i<n; i++) scanf("%d", &height[i]);
    height[n] = 0;
    process(n, height);
}