/*Cho file dữ liệu vào chứa một cây theo định dạng ví dụ sau. Hãy in ra bán kính của cây. (Nhưng testcase lại để là đường kính)
0 1 2 3 $
1 4 5 $
3 6 7 8 $
7 9 11 $
9 10 $
$$*/

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
    if(nodes[v] == NULL) nodes[v] = makenode(v);
    node* q = nodes[v];
    while(q->next != NULL){
        q = q->next;
    }
    q->next = makenode(u);
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

void printlist(){
    for(int i=0; i<maxlen; i++){
        if(exist[i] == 1){
            printf("%d:", i);
            node* p = nodes[i];
            while(p) { printf(" %d", p->key); p = p->next; }
            printf("\n");
        }
    }
}

int farnode, maxdepth = 0;
void dfs(int root){
    int stack[maxlen][2] = {0}, stacklen = 0, visited[maxlen] = {0};
    visited[root] = 1;
    stack[++stacklen][0] = root;
    stack[stacklen][1] = 0; 
    while(stacklen > 0){
        int u_key = stack[stacklen][0];
        int u_depth = stack[stacklen--][1];
        if(u_depth >= maxdepth){
            maxdepth = u_depth;
            farnode = u_key;
        }
        node* p = nodes[u_key];
        while(p != NULL){
            if(!visited[p->key]){
                visited[p->key] = 1;
                stack[++stacklen][0] = p->key;
                stack[stacklen][1] = u_depth + 1;
            }
            p = p->next;
        }
    }
}

int main(){
    input();
    // printlist();
    dfs(root);
    int bestnode = farnode;
    dfs(bestnode);
    printf("%d\n", maxdepth);
}
