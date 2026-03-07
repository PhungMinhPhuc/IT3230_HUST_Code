/*The data about bank transactions consists of a sequence of transactions: the information of each transaction has the following format:
                                        <from_account>   <to_account>   <money>   <time_point>   <atm>
In which:
•	<from_account>: the account from which money is transferred (which is a string of length from 6 to 20 )
•	<to_account>: the account which receives money in the transaction (which is a string of length from 6 to 20)
•	<money>: amount of money transferred in the transaction (which is an integer from 1 to 10000)
•	<time_point>: the time point at which the transaction is performed, it is a string under the format HH:MM:SS  (hour: minute: second)
•	<atm>: the code of the ATM where the transaction is taken (a string of length from 3 to 10)
Example: T00112233445 T001234002 2000 08:36:25 BIDV (at the ATM BIDV, account T00112233445 transfers 2000$ to account T001234002 at time point 08:36:25 (08 hour, 36 minutes, 25 seconds) 
A transaction cycle of length k starting from account a1 is defined to be a sequence of distinct account a1, a2, …, ak  in which there are transactions from account a1 to a2, from a2 to a3, …, from ak to a1.
Write a program that process the following queries: 
?number_transactions: compute the total number of transactions of the data
?total_money_transaction: compute the total amount of money of transactions  
?list_sorted_accounts: compute the sequence of bank accounts (including sending and receiving accounts) appearing in the transaction (sorted in an increasing (alphabetical) order)  
?total_money_transaction_from <account>: compute the total amount of money transferred from the account <account>  
?inspect_cycle <account> k : return 1 if there is a transaction cycle of length k, starting from <account>, and return 0, otherwise
Input (stdin)
The input consists of 2 blocks of information: the data block and the query block
•	The data block consists of lines:
o	Each line contains the information about a transaction described above
o	The data is terminated by a line containing #
•	The query block consists of lines:
o	Each line is a query described above
o	The query block is terminated by a line containing #
Output (stdout)
•	Print to stdout (in each line) the result of each query described above
Example
Input
T000010010 T000010020 1000 10:20:30 ATM1
T000010010 T000010030 2000 10:02:30 ATM2
T000010010 T000010040 1500 09:23:30 ATM1
T000010020 T000010030 3000 08:20:31 ATM1
T000010030 T000010010 4000 12:40:00 ATM2
T000010040 T000010010 2000 10:30:00 ATM1
T000010020 T000010040 3000 08:20:31 ATM1
T000010040 T000010030 2000 11:30:00 ATM1
T000010040 T000010030 1000 18:30:00 ATM1
#
?total_money_transaction_from T000010010
?total_money_transaction_from T000010030
#
Output
4500
4000
*/


// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// #include <stdlib.h>

// #define maxlen 100000
// #define has_size 10000

// typedef struct inf{
//     char from[21];
//     char to[21];
//     int money;
//     char time[12];
//     char atm[11];
// } inf;

// typedef struct node{
//     char key[25];
//     int value;
//     struct node* next;
// } node;

// node* 

// int hash funtion(){

// }








// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// #include <stdlib.h>

// #define maxlen 100000

// typedef struct inf{
//     char from[21];
//     char to[21];
//     int money;
//     char time[12];
//     char atm[11];
// } inf;

// typedef struct sort{
//     char r[21];
// } sort;

// typedef struct total{
//     char from[21];
//     int totalmoney;
// } total;

// inf *a;
// char c[100];
// sort *s;
// total *b;
// int n = 0, processed = 0, cntacc = 1, cntcyc = 0, k, found = 1, foundtotal = 0, foundcyc = 0, cntfrom = 0;
// char cycacc[21];
// int arr[1000][1000];

// int cmp1(const void* ptr1, const void* ptr2){
//     sort* x = (sort*)ptr1;
//     sort* y = (sort*)ptr2;
//     return strcmp(x->r, y->r);
// }

// int cmp2(const void* ptr1, const void* ptr2){
//     inf* x = (inf*)ptr1;
//     inf* y = (inf*)ptr2;
//     return strcmp(x->from, y->from);
// }

// int acc_to_arr(const char* a){ //Chuyển từ tên tài khoản bất kì từ mảng gốc sang chỉ số của nó ở mảng tên
//     for(int i=0; i<cntacc; i++){
//         if(strcmp(a, s[i].r) == 0) return i; 
//     }
// }

// void process(){ //Hàm xử lí sort: ghi đè và gán luôn cho các phần tử vào mảng s, vậy là các giá trị dưới cntacc là rác, có thể cho bằng 0 hoặc kệ =))) maybe
//     if(processed) return;
//     for(int i=0; i<n; i++){
//         strcpy(s[i].r, a[i].from);
//         strcpy(s[n+i].r, a[i].to);
//     }
//     qsort(s, n*2, sizeof(sort), cmp1);
//     for(int i=1; i<n*2; i++){
//         if(i == 2*n || (strcmp(s[i].r, s[i-1].r) != 0)){
//             strcpy(s[cntacc].r, s[i].r);
//             cntacc++;
//         }
//     }
//     processed = 1;
// }

// void processcyc(){
//         for(int i=0; i<n; i++){
//         arr[acc_to_arr(a[i].from)][acc_to_arr(a[i].to)] = 1;
//     }
//     foundcyc = 1;
// }

// int bs_user(total *a, int n, const char* key){
//     int l=0, r=n;
//     while(l<=r){
//         int m = (l+r)/2;
//         int c = strcmp(a[m].from, key);
//         if(c == 0) return m;
//         else if (c<0) l=m+1;
//         else r=m-1;
//     }
//     return -1;
// }

// // u: đỉnh hiện tại, start: đỉnh bắt đầu, k: độ dài chu trình, depth: độ sâu hiện tại, visited[]: mảng đánh dấu các đỉnh đã đi qua trong đường đi này
// void dfs(int u, int start, int k, int depth, int visited[]){
//     if(found == 1) return;
//     if(depth == k-1){
//         if(arr[u][start] == 1){
//             found = 1;
//             return;
//         }
//         return;
//     }
//     visited[u] = 1;
//     for(int v=0; v<cntacc; v++){
//         if(!visited[v] && arr[u][v]){
//             dfs(v, start, k, depth + 1, visited);
//             if(found == 1) return;
//         }
//     }
//     visited[u] = 0;
// }


// int main(){
//     a = (inf*) malloc(maxlen * sizeof(inf));
//     s = (sort*) malloc(maxlen * sizeof(sort));
//     b = (total*) malloc(maxlen*sizeof(total));
//     while(1){
//         if(!fgets(c, sizeof(c), stdin)) break;
//         c[strcspn(c,"\n\r")] = '\0';
//         if(c[0] == '#') break;
//         sscanf(c, "%s %s %d %s %s", a[n].from, a[n].to, &a[n].money, a[n].time, a[n].atm);
//         n ++;
//     }
//     while(1){
//         if(!fgets(c, sizeof(c), stdin)) break;
//         c[strcspn(c,"\n\r")] = '\0';
//         if(c[0] == '#') break;
//         if(strcmp(c, "?number_transactions") == 0){
//             printf("%d\n", n);
//         }
//         else if(strcmp(c, "?total_money_transaction") == 0){
//             int sum = 0;
//             for(int i=0; i<n; i++){
//                 sum += a[i].money;
//             }
//            printf("%d\n", sum);
//         }
//         else if(strncmp(c, "?total_money_transaction_from ", 30) == 0){
//             char acc[21];
//             sscanf(c + 30, "%s", acc);
//             int sumacc = 0;
//             if(!foundtotal){
//                 qsort(a, n, sizeof(inf), cmp2);
//                 for(int i=0; i<n; i++){
//                     if(i == 0 || strcmp(a[i].from, a[i-1].from) != 0){
//                         strcpy(b[cntfrom].from, a[i].from);
//                         b[cntfrom].totalmoney = 0;
//                         cntfrom++;
//                     }
//                     b[cntfrom-1].totalmoney += a[i].money;
//                 }
//                 foundtotal = 1;
//             }
//             //for(int i=0; i<cntfrom; i++) printf("%s %d\n", b[i].from, b[i].totalmoney);
//             int idx = bs_user(b, cntfrom, acc);
//             if(idx == -1) sumacc = 0;
//             else sumacc = b[idx].totalmoney;
//             printf("%d\n", sumacc);
//         }
//         else{
//             if(strcmp(c, "?list_sorted_accounts") == 0){
//                 process();
//                 for(int i=0; i<cntacc; i++) printf("%s ", s[i].r);
//                 printf("\n");
//             }
//             else if(strncmp(c, "?inspect_cycle ", 15) == 0){
//                 sscanf(c + 15, "%s %d", cycacc, &k);
//                 process();
//                 processcyc();
//                 found = 0;
//                 int visited[maxlen] = {0};
//                 dfs(acc_to_arr(cycacc), acc_to_arr(cycacc), k, 0, visited);
//                 printf("%d\n", found);
//             }
//         }
//     }
// }