/*Given a BST initialized by NULL. Perform a sequence of operations on a BST including:
insert k: insert a key k into the BST (do not insert if the key k exists)
Input
•Each line contains command under the form: “insert k”
•The input is terminated by a line containing #
Output
•Write the sequence of keys of nodes visited by the pre-order traversal (separated by a SPACE character)
Example
Input
insert 20
insert 10
insert 26
insert 7
insert 15
insert 23
insert 30
insert 3
insert 8
#
Output
20 10 7 3 8 15 26 23 30*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 100

typedef struct node{
    int key;
    struct node* lc;
    struct node* rc;
} node;

node* root = NULL;

node* makenode(int key){
    node* p = (node*)malloc(sizeof(node));
    p->key = key;
    p->lc = NULL;
    p->rc = NULL;
    return p;
}

node* insert(node* nodePtr, int key){
    if(nodePtr == NULL) nodePtr = makenode(key);
    else if(key < nodePtr->key) nodePtr->lc = insert(nodePtr->lc, key);
    else if(key > nodePtr->key) nodePtr->rc = insert(nodePtr->rc, key);
    return nodePtr;
}

void PreOrder(node* r){
    if(r == NULL) return;
    printf("%d ", r->key);
    PreOrder(r->lc);
    PreOrder(r->rc);
}

int main(){
    char c[maxlen];
    while(1){
        fgets(c, sizeof(c), stdin);
        c[strcspn(c, "\n\r")] = '\0';
        if(strcmp(c, "#") == 0) break;
        else if(strncmp(c, "insert ", 7) == 0){
            int m;
            sscanf(c+7, "%d", &m);
            root = insert(root, m);
        }
    }
    PreOrder(root);
}