/*Each node of a binary tree has a field id which is the identifier of the node. Build a binary tree and check if the tree is a balanced tree, compute the height of the given tree (the number of nodes of the tree can be upto 50000)
Input
Line 1 contains MakeRoot u: make the root of the tree having id = u
Each subsequent line contains: AddLeft or AddRightcommands with the format
AddLeft u v: create a node having id = u, add this node as a left-child of the node with id = v (if not exists)
AddRight u v: create a node having id = u, add this node as a right-child of the node with id = v (if not exists)
The last line contains * which marks the end of the input
Output
Write two integers z and h (separated by a SPACE character) in which h is the height (the number of nodes of the longest path from the root to a leaf) and z = 1 if the tree is balanced and z = 0, otherwise

Example
Input
MakeRoot 1
AddLeft 2 1
AddRight 3 1
AddLeft 9 2
AddRight 4 2
AddLeft 6 3
AddRight 5 3
AddLeft 7 4
AddRight 8 4
*
Output
1 4*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define maxlen 100000

typedef struct node{
    int id;
    struct node* lc;
    struct node* rc;
} node;

node* nodes[maxlen];
node* root = NULL;

node* makenode(int id){
    node* p = (node*)malloc(sizeof(node));
    p->id = id;
    p->lc = NULL;
    p->rc = NULL;
    nodes[id] = p;
    return p;
}

void makeroot(int id){
    root = makenode(id);
}

void addleft(int u, int v){
    node* p = nodes[v];
    if(p != NULL && p->lc == NULL && nodes[u] == NULL){
        p->lc = makenode(u);
    }
}

void addright(int u, int v){
    node* p = nodes[v];
    if(p != NULL && p->rc == NULL && nodes[u] == NULL){
        p->rc = makenode(u);
    }
}

int isbalanced = 1;
int check_balanced(node* r){
    if(r == NULL) return 0;
    int lh, rh;
    lh = check_balanced(r->lc);
    if(lh == -1) return -1;
    rh = check_balanced(r->rc);
    if(rh == -1) return -1;
    if(abs(lh - rh) > 1) isbalanced = 0;
    return lh > rh ? lh + 1 : rh + 1;
}

int main(){
    char queries[50];
    while(1){
        scanf("%s", queries);
        if(strcmp(queries, "*") == 0){
            printf("%d %d", isbalanced, check_balanced(root));
            break;
        }
        if(strcmp(queries, "MakeRoot") == 0){
            int id;
            scanf("%d", &id);
            makeroot(id);
        }
        else if(strcmp(queries, "AddLeft") == 0){
            int u, v;
            scanf("%d %d", &u, &v);
            addleft(u, v);
        }
        else if(strcmp(queries, "AddRight") == 0){
            int u, v;
            scanf("%d %d", &u, &v);
            addright(u, v);
        }
    }
}