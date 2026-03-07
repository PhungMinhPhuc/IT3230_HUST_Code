/*Given a sequence of integers a1, a2, ..., an. Perform a sequence of queries over this sequence including:
find-max: return the maximum element of the given sequence
find-min: return the minimum element of the given sequence 
sum: return the sum of the elements of the given sequence 
find-max-segment i j: return the maximum element of the subsequence from index i to index j (i <= j)

Input
The first block contains the information about the given sequence with the following format:
Line 1: contains a positive integer n (1 <= n <= )
Line 2: contains n integers a1, a2, ..., an (-1000 <= ai <= 1000)
The first block is terminated by a character *
The second block contains a sequence of queries defined above, each query is in a line. The second block is terminated a 3 characters ***

Output
Write the result of each query in a corresponding line
 
Example
Input
5
1 4 3 2 5
*
find-max
find-min
find-max-segment 1 3
find-max-segment 2 5
sum
***

Output
5
1
4
5
15
*/

#include <stdio.h>
#include <string.h>

#define maxlen 100000

int main(){
    int a;
    int n[maxlen];
    int result[maxlen], m = 0;
    scanf("%d", &a);
    for(int i=0; i<a; i++){
        scanf("%d", i+n);
    }
    getchar();
    char x[maxlen];
        while(1){
            if(!fgets(x, sizeof(x), stdin)) break;
            x[strcspn(x, "\n\r")] = '\0';
            if(strcmp(x,"***") == 0) break; //Để dòng này trước kiểm tra * vì nếu đặt ngược lại, x[0] luôn đúng khi gõ *** và vòng lặp sẽ chạy mãi
            if(x[0] == '*') continue;
            if(strcmp(x, "find-max") == 0){
                int max = n[0];
                for(int i=0; i<a; i++){
                    if(n[i] > max) max = n[i];
                }
                result[m]=max;
                m++;
            }
            else if(strcmp(x, "find-min") == 0){
                int min =  n[0];
                for(int i=0; i<a; i++){
                    if(n[i] < min) min = n[i];
                }
                result[m]=min;
                m++;
            }
            else if(strcmp(x, "sum") == 0){
                int sum = 0;
                for(int i=0; i<a; i++){
                    sum += n[i];
                }
                result[m] = sum;
                m++;
            }
            else{
                int l, r;
                if(sscanf(x, "find-max-segment %d %d", &l, &r) == 2){
                    int max = n[l-1];
                    for(int i=l-1; i<r; i++){
                        if(n[i] > max) max = n[i];
                    }
                    result[m] = max;
                    m++;
                }
            } 
        }
        for(int i=0; i<m; i++) printf("%d\n", result[i]);
}