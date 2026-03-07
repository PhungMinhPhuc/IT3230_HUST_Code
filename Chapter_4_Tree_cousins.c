/*Cho dữ liệu mô tả cây như ví dụ sau: dòng đầu tiên là giá trị của một node trong cây, các dòng sau mô tả cây. Hãy in ra các anh/chị/em họ của node đã cho.
Anh/Chị/Em họ được định nghĩa là các node có cùng độ sâu và khác "cha/mẹ" với node đã cho. Nếu không có thì in ra NOT FOUND
4
0 1 2 3 $
1 4 5 $
3 6 7 8 $
7 9 11 $
9 10 $
$$

Output ví dụ:
6 7 8*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 100

typedef struct node {
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

int level[maxlen], parentNode[maxlen];
void input(){
    char parent[10];
    while(1){
        scanf("%s", parent);
        if(strcmp(parent, "$$") == 0) break;
        int parent_key = atoi(parent);
        if(root == -1){
            root = parent_key;
            nodes[root] = makenode(root);
            level[root] = 0;
        }
        char child[10];
        while(1){
            scanf("%s", child);
            if(strcmp(child, "$") == 0) break;
            int child_key = atoi(child);
            addEdge(parent_key, child_key);
            level[child_key] = level[parent_key] + 1;
            parentNode[child_key] = parent_key;
        }
    }
}

void printlist(){
    for(int i=0; i<maxlen; i++){
        if(exist[i] == 1){
            printf("%d:", level[i]);
            node* p = nodes[i];
            while(p) { printf(" %d", p->key); p = p->next; }
            printf("\n");
        }
    }
}

void cousins(int key){
    for(int i=0; i<maxlen; i++){
        if(exist[i] == 1 && level[key] == level[i] && parentNode[key] != parentNode[i]){
            printf("%d ", i);
        }
    }
}

int main(){
    int target;
    scanf("%d", &target);
    input();
    cousins(target);
}