/*Mỗi nút trên cây có trường id (identifier) là một số nguyên (id của các nút trên cây đôi một khác nhau)
Thực hiện 1 chuỗi các hành động sau đây bao gồm các thao tác liên quan đến xây dựng cây và duyệt cây
· MakeRoot u: Tạo ra nút gốc u của cây
· Insert u v: tạo mới 1 nút u và chèn vào cuối danh sách nút con của nút v (nếu nút có id bằng v không tồn tại hoặc nút có id bằng u đã tồn tại thì không chèn thêm mới)
· PreOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự trước
· InOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự giữa
· PostOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự sau
Dữ liệu: bao gồm các dòng, mỗi dòng là 1 trong số các hành động được mô tả ở trên, dòng cuối dùng là * (đánh dấu sự kết thúc của dữ liệu).
Kết quả: ghi ra trên mỗi dòng, thứ tự các nút được thăm trong phép duyệt theo thứ tự trước, giữa, sau của các hành động PreOrder, InOrder, PostOrder tương ứng đọc được từ dữ liệu đầu vào
Ví dụ
Dữ liệu
MakeRoot 10
Insert 11 10
Insert 1 10
Insert 3 10
InOrder
Insert 5 11
Insert 4 11
Insert 8 3
PreOrder
Insert 2 3
Insert 7 3
Insert 6 4
Insert 9 4
InOrder
PostOrder
*
Kết quả
11 10 1 3
10 11 5 4 1 3 8
5 11 6 4 9 10 1 8 3 2 7
5 6 9 4 11 1 8 2 7 3 10*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 1000

typedef struct node{
    int id;
    struct node* leftMostChild;
    struct node* rightSibling;
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
    p->rightSibling = NULL;
    p->leftMostChild = NULL;
    nodes[n] = p;
    n++;
    return p;
}

void MakeRoot(int id){
    addNode(id);
}

node* findRightChild(node* r){
    node* p = r->leftMostChild;
    while(p->rightSibling != NULL) p = p->rightSibling;
    return p;
}

void insert(int u, int v){
    node* p = find(v);
    if(p != NULL){
        if(p->leftMostChild == NULL) p->leftMostChild = addNode(u);
        else findRightChild(p)->rightSibling = addNode(u);
    }
}

void preorder(node* r){
    printf("%d ", r->id);
    for(node* p = r->leftMostChild; p != NULL; p = p->rightSibling){
        preorder(p);
    }
}

void inorder(node* r){
    if(r == NULL) return;
    else{
        inorder(r->leftMostChild);
        printf("%d ", r->id);
        node* firstleft = r->leftMostChild;
        for(node* p = r->leftMostChild; p != NULL; p = p->rightSibling){
            if(p != firstleft) inorder(p);
        }
    }
}

void postorder(node* r){
    for(node* p = r->leftMostChild; p != NULL; p = p->rightSibling){
        postorder(p);
    }
    printf("%d ", r->id);
}

int main(){
    char queries[maxlen];
    while(1){
        scanf("%s", queries);
        if(strcmp(queries, "*") == 0) break;
        if(strcmp(queries, "MakeRoot") == 0){
            int id;
            scanf("%d", &id);
            MakeRoot(id);
        }
        if(strcmp(queries, "Insert") == 0){
            int u, v;
            scanf("%d %d", &u, &v);
            insert(u, v);
        }
        if(strcmp(queries, "PreOrder") == 0){
            preorder(nodes[0]);
            printf("\n");
        }
        if(strcmp(queries, "InOrder") == 0){
            inorder(nodes[0]);
            printf("\n");
        }
        if(strcmp(queries, "PostOrder") == 0){
            postorder(nodes[0]);
            printf("\n");
        }
    }
}