/*BST with insertion and removal operations

Each node of a Binary Search Tree (BST) T has a key (keys of nodes must be all different).
Perform a sequence of operations on a Binary Search Tree T (starting from empty BST) including:
insert k: insert a new node having key = k into T (do nothing if the node having key = k exists)
remove k: remove the node having key = k from T (in case the root is removed, then replace the root by the smallest-key node of the right sub-tree) 
preorder: print (in a new line) the sequence of keys of nodes of T visited by a Pre-Order traversal (elements are separated by a SPACE character)
postorder: print (in a new line) the sequence of keys of nodes of T visited by a Post-Order traversal (elements are separated by a SPACE character)

Input
Each line contains a command of three above format
The input is terminated by a line containing #

Output
Write the information of preorder, postorder commands described above

Example
Input 
insert 3
insert 4
remove 4
preorder
postorder
insert 5
insert 1
insert 8
remove 1
preorder
postorder
#

Output 
3
3
3 5 8
8 5 3*/

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

node* insert(node* r, int key){
    if(r == NULL) r = makenode(key);
    else if(key < r->key) r->lc = insert(r->lc, key);
    else if(key > r->key) r->rc = insert(r->rc, key);
    return r;
}

node* findMin(node* r){
    if(r == NULL) return NULL;
    while(r->lc != NULL) r = r->lc;
    return r;
}

//Cách 1: Đệ quy xóa node
// node* removeNode(node* r, int key){
//     node* temp;
//     if(r == NULL) return NULL;
//     else if(key < r->key) r->lc = removeNode(r->lc, key);
//     else if(key > r->key) r->rc = removeNode(r->rc, key);
//     else{
//     //     if(r->lc != NULL && r->rc != NULL){
//     //         temp = findMin(r->rc);
//     //         r->key = temp->key;
//     //         r->rc = removeNode(r->rc, temp->key);
//     //     }
//     //     else{
//     //         temp = r;
//     //         if(r->lc == NULL) r = r->rc;
//     //         else if(r->rc == NULL) r = r->lc;
//     //         free(temp);
//     //     }
//     // }
//     // return r;
//         if(r->lc == NULL){
//             temp = r->rc;
//             free(r);
//             return temp;
//         }
//         if(r->rc == NULL){
//             temp = r->lc;
//             free(r);
//             return temp;
//         }
//         temp = findMin(r->rc);
//         r->key = temp->key;
//         r->rc = removeNode(r->rc, temp->key);
//     }
//     return r;
// }

//Cách 2: tách ra thành 2 hàm: Chỉ xóa gốc không đệ quy, sau đấy đi tìm node rồi xóa node đấy coi như nó là gốc
node* removeRoot(node* r, int key){
    if(r == NULL) return NULL;
    if(r->rc == NULL){
        node* temp = r;
        r = r->lc;
        free(temp);
        return r;
    }
    node* p = r->rc;
    node* pp = r;
    if(p->lc == NULL){
        r->key = p->key;
        node* temp = p;
        r->rc = p->rc;
        free(temp);
        return r;
    }
    while(p->lc != NULL){
        pp = p;
        p = p->lc;
    }
        pp->lc = p->rc;
        r->key = p->key;
        free(p);
        return r;
}

node* removeNode(node* r, int key){
    if(r == NULL) return NULL;
    if(r->key == key) return removeRoot(r, key);
    else if(r->key > key) r->lc = removeNode(r->lc, key);
    else if(r->key < key) r->rc = removeNode(r->rc, key);
    return r;
}

void PreOrder(node* r){
    if(r == NULL) return;
    printf("%d ", r->key);
    PreOrder(r->lc);
    PreOrder(r->rc);
}

void PostOrder(node* r){
    if(r == NULL) return;
    PostOrder(r->lc);
    PostOrder(r->rc);
    printf("%d ", r->key);
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
        else if(strncmp(c, "remove ", 7) == 0){
            int m;
            sscanf(c+7, "%d", &m);
            root = removeNode(root, m);
        }
        else if(strcmp(c, "preorder") == 0){
            PreOrder(root);
            printf("\n");
        } 
        else if(strcmp(c, "postorder") == 0){
            PostOrder(root);
            printf("\n");
        } 
    }
}