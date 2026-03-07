/*Mỗi nút của một cây nhị phân T có trường id (định danh của nút, id không trùng lặp nhau). Thực hiện chuỗi các thao tác sau đây trên cây T (ban đầu, T là cây rỗng)
MakeRoot u: tạo một nút gốc có id bằng u
AddLeft u v: tạo một nút có id = u và chèn vào vị trí con trái của nút có id bằng v trên T (không thực hiện hành động chèn nếu nút có id bằng u đã tồn tại hoặc nút có id bằng v không tồn tại hoặc nút có id bằng v đã có nút con trái rồi)
AddRight u v: tạo một nút có id = u và chèn vào vị trí con phải của nút có id bằng v trên T (không thực hiện hành động chèn nếu nút có id bằng u đã tồn tại hoặc nút có id bằng v không tồn tại hoặc nút có id bằng v đã có nút con phải rồi)
PreOrder: đưa ra trên 1 dòng mới dãy id của các nút trong phép duyệt cây T theo thứ tự trước (các phần tử cách nhau bởi đúng 1 ký tự cách SPACE)
InOrder: đưa ra trên 1 dòng mới dãy id của các nút trong phép duyệt cây T theo thứ tự giữa (các phần tử cách nhau bởi đúng 1 ký tự cách SPACE)
PostOrder: đưa ra trên 1 dòng mới dãy id của các nút trong phép duyệt cây T theo thứ tự sau (các phần tử cách nhau bởi đúng 1 ký tự cách SPACE)
 
Input
Mỗi dòng là 1 trong số cách thao tác với định dạng được mô tả ở trên (thao tác MakeRoot chỉ xuất hiện đúng 1 lần và luôn ở ngay dòng đầu tiên). Kết thúc của dữ liệu input là dòng chứa duy nhất ký tự *

Output
Ghi ra trên 1 dòng kết quả của 1 trong số 3 thao tác InOrder, PreOrder, PostOrder mô tả ở trên

Example
Input
MakeRoot 1
AddLeft 2 1
AddRight 3 1
AddLeft 4 3
AddRight 5 2
PreOrder
AddLeft 6 5
AddRight 7 5
InOrder
*

Output
1 2 5 3 4
2 6 5 7 1 4 3*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 1000

typedef struct node{
    int id;
    struct node* rightChild;
    struct node* leftChild;
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
    p->leftChild = NULL;
    p->rightChild = NULL;
    nodes[n] = p;
    n++;
    return p;
}

void makeRoot(int id){
    addNode(id);
}

void addLeft(int u, int l){
    node* p = find(u);
    node* q = find(l);
    if(p != NULL && p->leftChild == NULL && q == NULL){
        q = addNode(l);
        p->leftChild = q;
    }
}

void addRight(int u, int r){
    node* p = find(u);
    node* q = find(r);
    if(p != NULL && p->rightChild == NULL && q == NULL){
        q = addNode(r);
        p->rightChild = q;
    }
}

void preorder(node* r){
    if(r == NULL) return;
    printf("%d ", r->id);
    preorder(r->leftChild);
    preorder(r->rightChild);
}

void inorder(node* r){
    if(r == NULL) return;
    inorder(r->leftChild);
    printf("%d ", r->id);
    inorder(r->rightChild);
}

void postorder(node* r){
    if(r == NULL) return;
    postorder(r->leftChild);
    postorder(r->rightChild);
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
            makeRoot(id);
        }
        if(strcmp(queries, "AddLeft") == 0){
            int u, l;
            scanf("%d %d", &l, &u);
            addLeft(u, l);
        }
        if(strcmp(queries, "AddRight") == 0){
            int u, r;
            scanf("%d %d", &r, &u);
            addRight(u, r);
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