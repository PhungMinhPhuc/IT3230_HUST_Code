/*Cây được cho bởi file vào có format như dưới đây. Hãy in ra 2 dòng, dòng 1 là độ cao của cây (Tính bằng số node) và dòng 2 là các node kể từ gốc nằm trên đường đi dài nhất dùng để tính độ cao của cây (luôn ưu tiên duyệt node bên trái).
0 1 2 3 $
1 4 5 $
3 6 7 8 $
7 9 11 $
9 10 $
$$
Ouput ví dụ:
5
0 3 7 9 10*/

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
    exist[u] = exist[v] = 1;
}

void input(){
    char parent[10];
    while(1){
        scanf("%s", parent);
        if(strcmp(parent, "$$") == 0) break;
        if(root == -1){
            root = atoi(parent);
            nodes[root] = makenode(root);
        }
        char child[10];
        while(1){
            scanf("%s", child);
            if(strcmp(child, "$") == 0) break;
            addEdge(atoi(parent), atoi(child));
        }
    }
}

int parent[maxlen], deepest, maxH = 0;
void height(int r, int h){
    if(maxH < h){
        maxH = h;
        deepest = r;
    }
    if(nodes[r] == NULL) return;
    node* p = nodes[r];
    while(p->next != NULL){
        parent[p->next->key] = r;
        height(p->next->key, h+1);

        p = p->next;
    }
}

int path[maxlen], pathlen = 0;
void findpath(int key){
    path[pathlen++] = key;
    if(key == root) return;
    findpath(parent[key]);
}

void printpath(){
    findpath(deepest);
    for(int i=pathlen-1; i>=0; i--) printf("%d ", path[i]);
}

int main(){
    input();
    height(root, 1);
    printf("%d\n", maxH);
    printpath();
}