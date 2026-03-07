/*Bài 3: Có một chuỗi các lệnh theo định dạng: <COMMAND> <ID> <VALUE>, trong đó các trường COMMAND, ID và VALUE cách nhau bởi dấu cách và có ý nghĩa như sau:
- <COMMAND> nhận một trong 2 giá trị ký tự 'I' hoặc 'A';  
  Nếu là 'I' thì lệnh đó cần chèn giá trị <VALUE> vào đầu danh sách có mã là <ID>;  
  Nếu là 'A' thì lệnh đó cần chèn giá trị <VALUE> vào cuối danh sách có mã là <ID>;
- <ID> nhận một trong 2 giá trị "1" hoặc "2" là mã xác định danh sách cần thao tác trong lệnh;  
  <VALUE> là một số nguyên thuộc [0, 1000], cần được thêm vào danh sách (đầu hoặc cuối tùy theo COMMAND là 'I' hay 'A').
Ví dụ về đầu vào và đầu ra:
Input:
I 1 5
I 2 6
I 1 3
A 1 8
I 2 9
I 2 10
#
Output:
3 10 5 9 8 6
Giải thích:  
Sau khi thực hiện các lệnh, ta có:
- Danh sách 1: 3 5 8 (đầu tiên thêm 5, sau đó chèn 3 vào đầu, cuối cùng thêm 8 vào cuối)  
- Danh sách 2: 10 9 6 (đầu tiên thêm 6, sau đó chèn 9 vào đầu, cuối cùng chèn 10 vào đầu)
Dưới đây là yêu cầu của bài:  
Hãy viết chương trình đọc các lệnh theo mô tả trên, tạo thành 2 danh sách, rồi in ra danh sách thứ 3 lấy các phần tử của danh sách 1 ở các vị trí thứ 1, 3, 5, ... và của danh sách 2 ở các vị trí 2, 4, 6, ... (bắt đầu đếm từ 1).  
Nếu hết phần tử của một danh sách trong quá trình in, thì các phần tử tiếp theo của danh sách còn lại sẽ được lấy tiếp tục.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 100000

typedef struct node{
    int key;
    struct node* next;
    struct node* prev;
} node;

node* heads[4];
node* tails[4];

node* makenode(int key){
    node* p = (node*)malloc(sizeof(node));
    p->key = key;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void addfirst(int id, int value){
    node* p = makenode(value);
    if(heads[id] == NULL) heads[id] = p;
    else{
        p->next = heads[id];
        heads[id]->prev = p;
        heads[id] = p;
    }
    if(tails[id] == NULL) tails[id] = p;
}

void addlast(int id, int value){
    node* p = makenode(value);
    if(tails[id] == NULL) tails[id] = p;
    else{
        p->prev = tails[id];
        tails[id]->next = p;
        tails[id] = p;
    }
    if(heads[id] == NULL) heads[id] = p;
}

void merge(node* heads1, node* heads2){
    node* p = heads1;
    node* q = heads2;
    while(p != NULL || q != NULL){
        if(p != NULL){
            printf("%d ", p->key);
            p = p->next;
        }
        if(q != NULL){
            printf("%d ", q->key);
            q = q->next;
        }
    }
}

int main(){
    char command[2];
    int id, value;
    while(1){
        scanf("%s", command);
        if(strcmp(command, "#") == 0) break;
        else if(strcmp(command, "I") == 0){
            scanf("%d %d", &id, &value);
            addfirst(id, value);
        }
        else if(strcmp(command, "A") == 0){
            scanf("%d %d", &id, &value);
            addlast(id, value);
        }
    }
    merge(heads[1], heads[2]);
}