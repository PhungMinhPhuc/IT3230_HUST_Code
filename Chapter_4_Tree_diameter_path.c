/*Cây được cho bởi dữ liệu như ví dụ sau, hãy in ra 2 dòng: dòng 1 là độ dài đường kính cây (tính bằng số cạnh) và dòng 2 là các node của đường kính theo thứ tự là các node trên đường đi theo đường kính từ node lá bên trái đến node lá bên phải. Toàn bô quá trình duyệt cây luôn ưu tiên duyệt phía bên trái trước.
0 1 2 3 $
1 4 5 $
3 6 7 8 14 $
7 9 11 $
9 10 $
10 19 $
8 12 $
12 13 $
14 15 $
15 16 $
16 17 18 $
$$

Output ví dụ:
8
19 10 9 7 3 14 15 16 17*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 100

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

int farnode, maxdepth = 0, parent[maxlen];
// void dfs(int root){ //Thực sự là dfs bằng stack thì lúc mà lấy khỏi stack nó lại ngược, muốn xuôi cũng được nma lười =))
//     int stack[maxlen][2] = {0}, stacklen = 0, visited[maxlen] = {0};
//     visited[root] = 1;
//     stack[++stacklen][0] = root;
//     stack[stacklen][1] = 0; 
//     while(stacklen > 0){
//         int u_key = stack[stacklen][0];
//         int u_depth = stack[stacklen--][1];
//         if(u_depth >= maxdepth){
//             maxdepth = u_depth;
//             farnode = u_key;
//         }
//         node* p = nodes[u_key];
//         while(p != NULL){
//             if(!visited[p->key]){
//                 visited[p->key] = 1;
//                 parent[p->key] = u_key;
//                 stack[++stacklen][0] = p->key;
//                 stack[stacklen][1] = u_depth + 1;
//             }
//             p = p->next;
//         }
//     }
// }        


int visited[maxlen] = {0}, leftmost[maxlen], rankleaf = 1;
void dfs(int root, int par, int depth){
    if(nodes[root] == NULL) return;
    if(depth > maxdepth){
        maxdepth = depth;
        farnode = root;
    }
    visited[root] = 1;
    node* p = nodes[root];
    while(p != NULL){
        if(!visited[p->key]){
            visited[p->key] = 1;
            parent[p->key] = root;
            leftmost[p->key] = rankleaf++;
            dfs(p->key, root, depth + 1);
        }
        p = p->next;
    }
}

int path[maxlen], pathlen = 0;
void findpath(int key, int bestnode){
    path[pathlen++] = key;
    if(key == bestnode) return;
    findpath(parent[key], bestnode);
}

int main(){
    input();
    // printlist();
    dfs(root, root, 0);
    int bestnode = farnode;
    int leftmost1[maxlen];
    for(int i=0; i<maxlen; i++){
        leftmost1[i] = leftmost[i];
        visited[i] = 0;
    }
    dfs(bestnode, bestnode, 0);
    printf("%d\n", maxdepth);
    findpath(farnode, bestnode);
    if(leftmost1[farnode] > leftmost1[bestnode]) for(int i=pathlen-1; i>=0; i--) printf("%d ", path[i]); 
    else for(int i=0; i<pathlen; i++) printf("%d ", path[i]); 
}