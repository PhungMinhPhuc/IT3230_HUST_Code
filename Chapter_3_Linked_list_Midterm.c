/*You are given n integers that are stored in a singly linked list using following declaration:
typedef struct Node {
    int data;
    struct Node *next;
}Node;
Determine whether this singly linked list is palindrome or not.
Note: You must use singly linked list with the given above declaration, otherwise you will get 0.
Input:
· The first line contains one integers:  n  (1 <= n <= 10^5)
· The last line contains n integers in the range [0, 9]
Ouput:
Print 1 if the singly linked list is palindrome, otherwise print 0
Example:
Input:
4
2 3 3 2
Output:
1 
Explanation: in the above example, the singly linked list contains 4 nodes: 2-->3-->3-->2 and it is palindrome.*/

/*Bài này đảo list tại vị trí 1/2, sau khi đảo xong xét duyệt theo 2 hướng*/

//Nhưng cách dưới đây không làm thế, làm đảo 2 list sau đó so, lười viết lại hàm nên copy cho nhanh =))
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define maxlen 10000

typedef struct node {
    int data;
    struct node *next;
} node;

node* makenode(int data){
    node* p = (node*)malloc(sizeof(node));
    p->data = data;
    p->next = NULL;
    return p;
}

node* addnode(node* head, int data){
    node* newNode = makenode(data);
    if(head == NULL) return newNode;
    else{
        node* p = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = newNode;
        return head;
    }
}

node* reverse(node* head){
    node* previous = NULL, * current = head, * following = NULL;
    while(current != NULL){
        following = current->next;
        current->next = previous;
        previous = current;
        current = following;
    }
    return previous;
}

void palindrome(node* head1, node* head2){
    node* p = head1;
    node* q = head2;
    while(p != NULL && q != NULL){
        if(p->data != q->data){
            printf("0");
            return;
        }
        p = p->next;
        q = q->next;
    }
    printf("1");
}

int main(){
    int n, data;
    node* head1 = NULL, * head2 = NULL;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &data);
        head1 = addnode(head1, data);
        head2 = addnode(head2, data);
    }
    head2 = reverse(head2);
    palindrome(head1, head2);
}