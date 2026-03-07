/*Each node of a Binary Search Tree (BST) T has a key (keys of nodes must be all different).
Perform a sequence of operations on a Binary Search Tree T (starting from empty BST) including:
insert k: insert a new node having key = k into T
preorder: print (in a new line) the sequence of keys of nodes of T visited by a Pre-Order traversal (elements are separated by a SPACE character)
postorder: print (in a new line) the sequence of keys of nodes of T visited by a Post-Order traversal (elements are separated by a SPACE character)
Input
Each line contains a command of three above format
The input is terminated by a line containing #
Output
Write the information of preorder, postorder commands described above
Example
Input
insert 5
insert 9
insert 2
insert 1
preorder
insert 8
insert 5
insert 3
postorder
#
Output
5 2 1 9
1 3 2 8 9 5*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 100000

typedef struct node{
    int key;
    struct node* lc;
    struct node* rc;
} node;

node* root;
int n = 0, exist[maxlen];

node* makenode(int key){
    node* p = (node*)malloc(sizeof(node));
    p->key = key;
    p->lc = NULL;
    p->rc = NULL;
    exist[key] = 1;
    return p;
}

node* insert(node* root, int key){
    if(exist[key] == 0){
        if(root == NULL) return makenode(key);
        node* p = root;
        if(p->key > key) p->lc = insert(p->lc, key);
        if(p->key < key) p->rc = insert(p->rc, key);
    }
    return root;
}

void preOrder(node* root){
    if(root == NULL) return;
    printf("%d ", root->key);
    preOrder(root->lc);
    preOrder(root->rc);
}

void postOrder(node* root){
    if(root == NULL) return;
    postOrder(root->lc);
    postOrder(root->rc);
    printf("%d ", root->key);
}

int main(){
    char query[50];
    while(1){
        scanf("%s", query);
        if(strcmp(query, "#") == 0) break;
        else if(strcmp(query, "insert") == 0){
            int key;
            scanf("%d", &key);
            root = insert(root, key);
        }
        else if(strcmp(query, "preorder") == 0){
            preOrder(root);
            printf("\n");
        }
        else if(strcmp(query, "postorder") == 0){
            postOrder(root);
            printf("\n");
        }
    }
}