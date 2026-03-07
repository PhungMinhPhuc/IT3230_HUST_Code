/*Viết chương trình thực hiện công việc sau:
Xây dựng hai danh sách liên kết đơn với các nút có khóa được cung cấp ban đầu gồm các cặp số (hệ số, số mũ) là dãy (a0,0), (a1,1), ..., (an-1,n-1) và dãy (b0,0), (b1,1), ..., (bm-1,m-1) biểu diễn cho các hàm số dạng đa thức p(x) = a0*x^0 + a1*x^1 + ... + an-1*x^(n-1) và q(x) = b0*x^0 + b1*x^1 + ... + bm-1*x^(m-1). 
Yêu cầu thực hiện tính tổng (hoặc hiệu) hai đa thức này.
Chú ý tất cả các danh sách ứng với đa thức p(x), đa thức q(x) và đa thức tổng (hoặc hiệu) không được tồn tại nút có khóa với hệ số = 0 (với trường hợp p(x)=0, q(x)=0 và p(x) + q(x) = 0 (hoặc p(x) - q(x) = 0) thì danh sách tương ứng với chúng sẽ chỉ chứa một nút có khóa là (0,0)).
Input
Dòng 1: ghi số nguyên dương n (1 <= n <= 1000)
Dòng 2: ghi các số nguyên a
Dòng 3: ghi số nguyên dương m (1 <= m <= 1000)
Dòng 4: ghi các số nguyên b
Các dòng tiếp theo lần lượt là một trong hai lệnh dưới đây:
plus: tính tổng hai đa thức
minus: tính hiệu hai đa thức
Output
Ghi ra số nút và dãy khóa của danh sách mới thu được sau khi tính tổng (hoặc hiệu), chú ý nếu hệ số = 0 không tồn tại nút thì vẫn phải ghi khóa = 0 ra.
-----------------------------------
Example1:
Input
5
-3 2 0 1 -7 
4
4 0 5 -1
plus
Output
4 1 2 5 0 -7
-----------------------------------
Example2:
Input
2
-1 -2 
2
-1 -2
minus
Output
1 0*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 1000

typedef struct term{
    int coefficient;
    int exponent;
    struct term * next;
} term;

void printlist(term* head){
    term* p = head;
    while(p != NULL){
        printf("%d ", p->coefficient);
        p = p->next;
    }
    printf("\n");
}

term* makenode(int coefficient, int exponent){
    term* p = (term*)malloc(sizeof(term));
    p->coefficient = coefficient;
    p->exponent = exponent;
    p->next = NULL;
    return p;
}

term* addterm(term* head, int coefficient, int exponent){
    term* newnode = makenode(coefficient, exponent);
    if(head == NULL){
        return newnode;
    }
    term* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}

void plus(term* head_1, term* head_2, term* head_3, int count){
    term* a = head_1;
    term* b = head_2;
    while(a != NULL || b != NULL){
        if(a == NULL || (b != NULL && b->exponent < a->exponent)){
            head_3 = addterm(head_3, b->coefficient, b->exponent);
            if(b->coefficient != 0) count++;
            b = b->next;
        }
        else if(b == NULL || (a != NULL && a->exponent < b->exponent)){
            head_3 = addterm(head_3, a->coefficient, a->exponent);
            if(a->coefficient != 0) count++;
            a = a->next;
        }
        else{
            head_3 = addterm(head_3, a->coefficient + b->coefficient, a->exponent);
            if(a->coefficient + b->coefficient != 0) count++;
            a = a->next;
            b = b->next;
        }
    }
    if(count == 0) printf("1 0");
    else{
        printf("%d ", count);
        printlist(head_3);
    }
}

void minus(term* head_1, term* head_2, term* head_3, int count){
    term* a = head_1;
    term* b = head_2;
    while(a != NULL || b != NULL){
        if(a == NULL || (b != NULL && b->exponent < a->exponent)){
            head_3 = addterm(head_3, - b->coefficient, b->exponent);
            if(b->coefficient != 0) count++;
            b = b->next;
        }
        else if(b == NULL || (a != NULL && a->exponent < b->exponent)){
            head_3 = addterm(head_3, a->coefficient, a->exponent);
            if(a->coefficient != 0) count++;
            a = a->next;
        }
        else{
            head_3 = addterm(head_3, a->coefficient - b->coefficient, a->exponent);
            if(a->coefficient - b->coefficient != 0) count++;
            a = a->next;
            b = b->next;
        }
    }
    if(count == 0) printf("1 0");
    else{
        printf("%d ", count);
        printlist(head_3);
    }
}

int main(){
    int n, m, a, b; 
    char s[50];
    term* head_1 = NULL, * head_2 = NULL, * head_3 = NULL;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a);
        head_1 = addterm(head_1, a, i);
    }
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d", &b);
        head_2 = addterm(head_2, b, i);
    }
    getchar();
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n\r")] = '\0';
    if(strcmp(s, "plus") == 0){
        plus(head_1, head_2, head_3, 0);
    }
    else if(strcmp(s, "minus") == 0){
        minus(head_1, head_2, head_3, 0);
    }
}