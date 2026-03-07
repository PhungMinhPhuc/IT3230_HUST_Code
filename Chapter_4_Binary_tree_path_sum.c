/*Each node in a binary tree T has a field "id" (unique node identifier). Perform a series of the following operations on tree T (initially, T is an empty tree):
• MakeRoot u: Create a root node with id u.
• AddLeft u v: Create a node with id u and insert it as the left child of the node with id v in T (do not perform the insertion if the node with id u already exists, or the node with id v does not exist, or the node with id v already has a left child).
• AddRight u v: Create a node with id u and insert it as the right child of the node with id v in T (do not perform the insertion if the node with id u already exists, or the node with id v does not exist, or the node with id v already has a right child).
• PathSum: Give an integer targetSum, return True if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
Input: Each line represents one of the described operations with the format as described above. The end of the input data is marked by a line containing only the character "*".
Output: Write "True" or "False" with each PathSum command
Example:
MakeRoot 1
AddLeft 2 1
AddRight 3 1
AddLeft 4 3
AddRight 5 2
AddLeft 6 5
AddRight 7 5
PathSum 4
PathSum 5
PathSum 8
PathSum 14
PathSum 15
PathSum 20
*
Output:
False
False
True
True
True
False*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 10000

typedef struct node{
    int id;
    struct node* lc;
    struct node* rc;
} node;

node* nodes[maxlen];
int n = 0;

node* find(int id){
    for(int i=0; i<n; i++){
        if(nodes[i]->id == id) return nodes[i];
    }
    return NULL;
}

node* makenode(int id){
    node* p = (node*)malloc(sizeof(node));
    p->id = id;
    p->lc = NULL;
    p->rc = NULL;
    nodes[n++] = p;
    return p;
}

void makeroot(int id){
    makenode(id);
}

void addleft(int u, int v){
    node* p = find(v);
    if(p != NULL && p->lc == NULL && find(u) == NULL){
        p->lc = makenode(u);
    }
}

void addright(int u, int v){
    node* p = find(v);
    if(p != NULL && p->rc == NULL && find(u) == NULL){
        p->rc = makenode(u);
    }
}

int pathsum(node* r, int sum, int val){
    if(r == NULL) return 0;
    val += r->id;
    if(r->lc == NULL && r->rc == NULL){
        if(sum == val) return 1;
    }
    return pathsum(r->lc, sum, val) || pathsum(r->rc, sum, val);
}

int main(){
    char queries[50];
    while(1){
        scanf("%s", queries);
        if(strcmp(queries, "*") == 0) break;
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
        else if(strcmp(queries, "PathSum") == 0){
            int sum;
            scanf("%d", &sum);
            if(pathsum(nodes[0], sum, 0) == 0) printf("False\n");
            else printf("True\n");
        }
    }
}