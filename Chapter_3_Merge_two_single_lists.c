/*Viết chương trình thực hiện công việc sau:
Xây dựng hai danh sách liên kết đơn với các khóa được cung cấp ban đầu là dãy a1, a2, ..., an và dãy b1, b2, ..., bm (các khóa của danh sách a và b đều đã được sắp xếp theo thứ tự không tăng (hoặc không giảm)); sau đó thực hiện trộn hai danh sách này thành danh sách mới với các khóa đã được sắp xếp theo thứ tự không tăng (hoặc không giảm)
Input
Dòng 1: ghi số nguyên dương n (1 <= n <= 1000)
Dòng 2: ghi các số nguyên dương a
Dòng 3: ghi số nguyên dương m (1 <= m <= 1000)
Dòng 4: ghi các số nguyên dương b
Các dòng tiếp theo lần lượt là một trong hai lệnh dưới đây:
iSort: trộn hai danh sách này thành danh sách mới với thứ tự các khóa không giảm
dSort: trộn hai danh sách này thành danh sách mới với thứ tự các khóa không tăng
Output
Ghi ra dãy khóa của danh sách mới thu được sau khi trộn
-----------------------------------
Example1:
Input
5
5 4 3 2 1
4
8 5 3 1
dSort
Output
8 5 5 4 3 3 2 1 1*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 1000

typedef struct list{
    int num;
    struct list* next;
} list;

list* makenode(int num){
    list* p = (list*)malloc(sizeof(list));
    p->num = num;
    p->next = NULL;
    return p;
}

list* addnode(list* head, int num){
    list* newnode = makenode(num);
    if(head == NULL) return newnode;
    else{
        list* p = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = newnode;
        return head;
    }
}

list* reverse(list* head){
    list* previous = NULL, * current = head, * following = NULL;
    while(current != NULL){
        following = current->next;
        current->next = previous;
        previous = current;
        current = following;
    }
    head = previous;
    return head;
}

void mergeListDecrease(list* head_1, list* head_2, list* head_3){
    list* a = head_1;
    list* b = head_2;
    while(a != NULL || b != NULL){
        if(a == NULL || (b != NULL && a->num < b->num)){
            head_3 = addnode(head_3, b->num);
            b = b->next;
        }
        else if(b == NULL || (a != NULL && a->num > b->num)){
            head_3 = addnode(head_3, a->num);
            a = a->next;
        }
        else{
            head_3 = addnode(head_3, a->num);
            head_3 = addnode(head_3, b->num);
            a = a->next;
            b = b->next;
        }
    }
    list* c = head_3;
    while(c != NULL){
        printf("%d ", c->num);
        c = c->next;
    }
}

void mergeListIncrease(list* head_1, list* head_2, list* head_3){
    list* a = head_1;
    list* b = head_2;
    while(a != NULL || b != NULL){
        if(a == NULL || (b != NULL && a->num < b->num)){
            head_3 = addnode(head_3, b->num);
            b = b->next;
        }
        else if(b == NULL || (a != NULL && a->num > b->num)){
            head_3 = addnode(head_3, a->num);
            a = a->next;
        }
        else{
            head_3 = addnode(head_3, a->num);
            head_3 = addnode(head_3, b->num);
            a = a->next;
            b = b->next;
        }
    }
    list* pre = NULL,* fol = NULL;
    list* cur = head_3;
    while(cur != NULL){
        fol = cur->next;
        cur->next = pre;
        pre = cur;
        cur = fol;
    }
    head_3 = pre;
    list* c = head_3;
    while(c != NULL){
        printf("%d ", c->num);
        c = c->next;
    }
}

void printlist(list* head){
    list* p = head;
    while(p != NULL){
        printf("%d ", p->num);
        p = p->next;
    }
}

int main(){
    int n, m, a, b;
    char s[20];
    list* head_1 = NULL, * head_2 = NULL, * head_3 = NULL;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a);
        head_1 = addnode(head_1, a);
    }
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d", &b);
        head_2 = addnode(head_2, b);
    }
    getchar();
    if(head_1->num < head_1->next->num) head_1 = reverse(head_1);
    if(head_2->num < head_2->next->num) head_2 = reverse(head_2);
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n\r")] = '\0';
    if(strcmp(s, "iSort") == 0) mergeListIncrease(head_1, head_2, head_3);
    else mergeListDecrease(head_1, head_2, head_3);
}