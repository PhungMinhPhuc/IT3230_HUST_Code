/*Viết chương trình thực hiện công việc sau:
Xây dựng danh sách liên kết với các khóa được cung cấp ban đầu là dãy a1, a2, …, an, sau đó thực hiện các thao tác trên danh sách bao gồm: thêm 1 phần tử vào đầu, vào cuối danh sách, hoặc vào trước, vào sau 1 phần tử nào đó trong danh sách, hoặc loại bỏ 1 phần tử nào đó trong danh sách

Input
Dòng 1: ghi số nguyên dương n (1 <= n <= 1000)
Dòng 2: ghi các số nguyên dương a1, a2, …, an.
Các dòng tiếp theo lần lượt là các lệnh để thao tác (kết thúc bởi ký hiệu #) với các loại sau:
addlast k: thêm phần tử có key bằng k vào cuối danh sách (nếu k chưa tồn tại)
addfirst k: thêm phần tử có key bằng k vào đầu danh sách (nếu k chưa tồn tại)
addafter u v: thêm phần tử có key bằng u vào sau phần tử có key bằng v trên danh sách (nếu v đã tồn tại trên danh sách và u chưa tồn tại)
addbefore u v: thêm phần tử có key bằng  u vào trước phần tử có key bằng v trên danh sách (nếu v đã tồn tại trên danh sách và u của tồn tại)
remove k: loại bỏ phần tử có key bằng k khỏi danh sách
reverse: đảo ngược thứ tự các phần tử của danh sách (không được cấp phát mới các phần tử, chỉ được thay đổi mối nối liên kết)
Output
Ghi ra dãy khóa của danh sách thu được sau 1 chuỗi các lệnh thao tác đã cho

Example
Input
5
5 4 3 2 1
addlast 3
addlast 10
addfirst 1
addafter 10 4
remove 1
#

Output
5 4 3 2 10 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 10000

typedef struct node{
    int key;
    struct node* next;
} node;

node* makenote(int v){
    node* p = (node*)malloc(sizeof(node));
    p->key = v;
    p->next = NULL;
    return p;
}

node* exists_key(node*head, int key){
    node* p = head;
    while(p != NULL){
        if(p->key == key) return p;
        p = p->next;
    }
    return NULL;
}

int exists(node* head, node* u){
    node* p = head;
    while(p != NULL){
        if(u == p) return 1;
        p = p->next;
    }
    return 0;
}

void printlist(node* p){
    while(p != NULL){
        printf("%d ", p->key);
        p = p->next;
    }
}

node* findlastnode(node* head){
    node* p = head;
    while(p != NULL){
        if(p->next == NULL) return p;
        p = p->next;
    }
    return NULL;
}

node* insertlast(node* head, int v){
    node* new_node = makenote(v);
    if(head == NULL) return new_node;
    else{
        node* lastnode = findlastnode(head);
        lastnode->next = new_node;
        return head;
    }
}

node* insertfirst(node* head, int v){
    node* new_node = makenote(v);
    if(head == NULL) return new_node;
    else{
        new_node->next = head;
        head = new_node;
        return head;
    }
}

node* prevnode(node* head, node* u){
    node* p = head;
    while(p != NULL){
        if(p->next == u) return p;
        p = p->next;
    }
    return NULL;
}

node* insertbefore(node* head, node* u, int v){
    node* p = prevnode(head, u);
    if(p == NULL && u != NULL) return head;
    node* q = makenote(v);
    if(u == NULL){
        if(head == NULL) return q;
        q->next = head;
        return q;
    }
    q->next = u;
    p->next = q;
    return head;
}

node* insertafter(node* head, node* u, int v){
    if(exists(head, u) == 0) return head;
    node* q = makenote(v);
    if(u->next == NULL){
        u->next = q;
        return head;
    }
    q->next = u->next;
    u->next = q;
    return head;
}

node* removenode_recursive(node* head, node* u){
    if(head == NULL || u == NULL) return head;
    if(head == u){
        head = head->next;
        free(u);
        return head;
    }
    else head->next = removenode_recursive(head->next, u);
}

node* removenode(node* head, node* u){
    if(head == NULL || u == NULL) return head;
    if(head == u){
        head = head->next;
        free(u);
        return head;
    }
    node* pre = head;
    node* cur = head->next;
    while(cur != NULL){
        if(cur == u){
            pre->next = cur->next; //u->next
            free(u);
            break;
        }
        pre = cur;
        cur = cur->next;
    }
    return head;
}

node* reverse(node* head){
    node* pre = NULL,* fol = NULL;
    node* cur = head;
    while(cur != NULL){
        fol = cur->next;
        cur->next = pre;
        pre = cur;
        cur = fol;
    }
    head = pre;
    return head;
}

int main(){
    int n;
    scanf("%d", &n);
    node* head = NULL;
    node* tail = NULL;
    for(int i=0; i<n; i++){
        int c;
        scanf("%d", &c);
        node* new_node = makenote(c);
        if(head == NULL) head = tail = new_node;
        else{
            tail->next = new_node;
            tail = new_node;
        }
    }
    char x[100];
    getchar();
    while(1){
        if(!fgets(x, sizeof(x), stdin)) break;
        x[strcspn(x, "\n\r")] = '\0';
        if(strcmp(x, "#") == 0) break;
        if(strncmp(x, "addlast ", 8) == 0){
            int m;
            sscanf(x+8, "%d", &m);
            if(exists_key(head, m) == NULL) head = insertlast(head, m);
        }
        else if(strncmp(x, "addfirst ", 9) == 0){
            int m;
            sscanf(x+9, "%d", &m);
            if(exists_key(head, m) == NULL) head = insertfirst(head, m);
        }
        else if(strncmp(x, "addafter ", 9) == 0){
            int m, k;
            sscanf(x+9, "%d %d", &k, &m);
            node* temp = exists_key(head, m);
            node* tempk = exists_key(head, k);
            if(temp != NULL && tempk == NULL) head = insertafter(head, temp, k);
        }
        else if(strncmp(x, "addbefore ", 10) == 0){
            int m, k;
            sscanf(x+10, "%d %d", &k, &m);
            node* temp = exists_key(head, m);
            node* tempk = exists_key(head, k);
            if(temp != NULL && tempk == NULL) head = insertbefore(head, temp, k);
        }
        else if(strncmp(x, "remove ", 7) == 0){
            int m;
            sscanf(x+7, "%d", &m);
            node* temp = exists_key(head, m);
            head = removenode(head, temp);
        }
        else if (strcmp(x, "reverse") == 0){
            head = reverse(head);
        }
    }
    printlist(head);
}