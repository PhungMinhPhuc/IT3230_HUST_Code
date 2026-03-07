/*Given 2 linked lists  (with id = 1 and id = 2, respectively): each node contains a non-negative integer, the nodes are sorted in ascending order (values at nodes can be equal). Consider the following querries:
- insert <list_id> <number> : is used to insert the <number> value into list_id while ensuring the ascending sort of linked_list.
For example, linked list 1 contains the following values: 1 2 7; The insert 1 5 statement is used to insert the value 5 into the linked list 1 so that the values in the linked list 1 are still sorted in ascending order. Therefore, the linked list obtained after insertion is 1 2 5 7.
- remove <list_id> <k> : is used to remove the kth value in linked list with id = <list_id>. Note: the elements in the linked list are indexed from 0, so if k = 0, it means we delete the first node.
For example, linked list 2 is containing the values: 1 2 7, the query remove 2 1 will remove the 1st element in list 2, so the linked list 2 obtained after deletion is: 1 7.
- print <list_id> :prints out the elements in the linked list with id = <list_id>
- merge : merge the two given linked lists to create a new linked list whose elements in the new linked list are still sorted by ascending value (note: there might be nodes with the same values). Print out the new linked_list after merging.
Input:
- The first line is the values in the linked list 1, ending with the value -1.
- The second 2 is the values in the linked list 2, ending with the value -1.
- Each of next line is a query of  either insert, or remove, merge, print.
Output:
Output of the query if existing

Example:
Input:
1 3 5 8 9 -1
2 6 11 -1
insert 1 7
insert 2 5
remove 1 4
remove 2 2
print 1
print 2
merge

Output
1 3 5 7 9
2 5 11
1 2 3 5 5 7 9 11*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define maxlen 10000

typedef struct node{
    int key;
    struct node* next;
} node;

node* Nodes[5];

node* makenode(int value){
    node* p = (node*)malloc(sizeof(node));
    p->key = value;
    p->next = NULL;
    return p;
}

node* insert(int listID, int value){
    node* head = Nodes[listID];
    node* newnode = makenode(value);
    if(Nodes[listID] == NULL) return newnode;
    else {
        node* p = Nodes[listID];
        node* prev = NULL;
        while(p != NULL && p->key > value){
            prev = p;
            p = p->next;
        }
        if(prev == NULL){
            newnode->next = Nodes[listID];
            Nodes[listID] = newnode;
        }
        else{
            newnode->next = p;
            prev->next = newnode;
        }
        return Nodes[listID];
    }
}

void printlist(node* head){
    node* p = head;
    while(p->next != NULL){
        printf("%d ", p->key);
        p = p->next;
    }
}

int main(){
    char query[20];
    while(1){
        scanf("%s", query);
        if(strcmp(query, "insert") == 0){
            int id, number;
            scanf("%d %d", &id, &number);
            Nodes[id] = insert(id, number);
        }
        else if(strcmp(query, "print") == 0){
            int id;
            scanf("%d", &id);
            printlist(Nodes[id]);
            return 0;
        }
    }
}