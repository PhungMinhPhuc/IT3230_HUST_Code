/* Vẽ cây theo mẫu
0 1 2 3 $
1 4 5 $
3 6 7 8 $
7 9 11 $
9 10 $
$$
Output:
0
+---1
|   +---4
|   +---5
+---2
+---3
    +---6
    +---7
    |   +---9
    |   |   +---10
    |   +---11
    +---8
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 10000

typedef struct node{
    int key;
    struct node* next;
} node;

node* nodes[maxlen];
int exist[maxlen] = {0}, root = -1;

node* makenode(int key){
    node* p = (node*)malloc(sizeof(node));
    p->key = key;
    p->next = NULL;
    return p;
}

void addEdge(int u, int v){
    if(nodes[u] == NULL) nodes[u] = makenode(u);
    node* p = nodes[u];
    while(p->next != NULL){
        p = p->next;
    }
    p->next = makenode(v);
    exist[u] = exist[v] = 1;
}

void input(){
    char parent[10];
    while(1){
        scanf("%s", parent);
        if(root == -1) root = atoi(parent);
        if(strcmp(parent, "$$") == 0) break;
        char child[10];
        while(1){
            scanf("%s", child);
            if(strcmp(child, "$") == 0) break;
            addEdge(atoi(parent), atoi(child));
        }
    }
}

int isLast[maxlen] = {0};
void drawtree(int r, int depth){
    for(int i=0; i<depth-1; i++){
        if(isLast[i] == 1) printf("    ");
        else printf("|   ");
    }
    if(depth > 0) printf("+---");
    printf("%d\n", r);
    if(nodes[r] == NULL) return;
    if(nodes[r]->next != NULL){
        node* p = nodes[r];
        while(p->next != NULL){
            if(p->next->next == NULL) isLast[depth] = 1;
            drawtree(p->next->key, depth + 1);
            isLast[depth] = 0;
            p = p->next;
        }
    }
}

int main(){
    input();
    drawtree(0, 0);
}
