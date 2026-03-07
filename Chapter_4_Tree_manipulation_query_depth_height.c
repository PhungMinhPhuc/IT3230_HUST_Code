/*Mỗi nút trên 1 cây có trường id (identifier) là một số nguyên (id của các nút trên cây đôi một khác nhau)
Thực hiện 1 chuỗi các hành động sau đây bao gồm các thao tác liên quan đến xây dựng cây và duyệt cây
· MakeRoot u: Tạo ra nút gốc u của cây
· Insert u v: tạo mới 1 nút u và chèn vào cuối danh sách nút con của nút v (nếu nút có id bằng v không tồn tại hoặc nút có id bằng u đã tồn tại thì không thêm mới)
· Height u:  Tính và trả về độ cao của nút u
· Depth u: Tính và trả về độ sâu của nút u
Biết rằng dữ liệu đầu vào có 1 lệnh duy nhất là MakeRoot và luôn ở dòng đầu tiên
· Dữ liệu: bao gồm các dòng, mỗi dòng có định dạng như mô tả ở trên, trong đó dòng cuối dùng ghi * (dấu hiệu kết thúc dữ liệu)
· Kết quả: ghi ra mỗi dòng kết quả của các lệnh Height và Depth tương ứng đọc được từ đầu vào
Ví dụ:
Dữ liệu
MakeRoot 10
Insert 11 10
Insert 1 10
Insert 3 10
Insert 5 11
Insert 4 11
Height 10
Depth 10
Insert 8 3
Insert 2 3
Insert 7 3
Insert 6 4
Insert 9 4
Height 10
Depth 10
Depth 3
*
Kết quả
3
1
4
1
2*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define maxlen 10000

typedef struct node{
    int id;
    struct node* lmc;
    struct node* rs;
} node;

node* nodes[maxlen];
int n = 0;

node* find(int id){
    for(int i=0; i<n; i++){
        if(nodes[i]->id == id) return nodes[i];
    }
    return NULL;
}

node* addNode(int id){
    node* p = (node*)malloc(sizeof(node));
    p->id = id;
    p->lmc = NULL;
    p->rs = NULL;
    nodes[n++] = p;
    return p;
}

void MakeRoot(int id){
    addNode(id);
}

node* findRightChild(node* r){
    node* p = r->lmc;
    while(p->rs != NULL){
        p = p->rs;
    }
    return p;
}

void insert(int u, int v){
    node* p = find(v);
    if(p != NULL){
        if(p->lmc == NULL) p->lmc = addNode(u);
        else findRightChild(p)->rs = addNode(u);
    }
}

void printtree(node* r){
    if(r == NULL) return;
    printf("%d ", r->id);
    printtree(r->lmc);
    printtree(r->rs);
}

int height(node* r){
    if(r == NULL) return 0;
    int maxH = 0;
    node* p = r->lmc;
    while(p != NULL){
        int h = height(p);
        if(h > maxH) maxH = h;
        p = p->rs;
    }
    return maxH + 1;
}

int depth(node* r,int id, int d){//d la do sau cua nut r
    if(r == NULL) return -1;
    if(r->id == id) return d;
    node* p = r->lmc;
    while(p != NULL){
        if(p->id == id) return d + 1;
        int res = depth(p, id, d+1);
        if(res > 0) return res;
        p = p->rs;
    }
    return -1;
}

int main(){
    char queries[50];
    while(1){
        scanf("%s", queries);
        if(strcmp(queries, "*") == 0) break;
        else if(strcmp(queries, "MakeRoot") == 0){
            int id;
            scanf("%d", &id);
            MakeRoot(id);
        }
        else if(strcmp(queries, "Insert") == 0){
            int u, v;
            scanf("%d %d", &u, &v);
            insert(u, v);
        }
        else if(strcmp(queries, "Height") == 0){
            int u;
            scanf("%d", &u);
            printf("%d\n", height(find(u)));
        }
        else if(strcmp(queries, "Depth") == 0){
            int u;
            scanf("%d", &u);
            printf("%d\n", depth(nodes[0], u, 1));
        }
    }
}