/*Thực hiện 1 chuỗi các hành động sau đây bao gồm các thao tác liên quan đến xây dựng cây và duyệt cây
· MakeRoot u: Tạo ra nút gốc u của cây
· Insert u v: tạo mới 1 nút u và chèn vào cuối danh sách nút con của nút v
· CountLeaves u:  đếm và trả ra số nút lá trên cây có gốc là u
· CountKChildren u k: đếm và trả về số nút có đúng k nút con trên cây gốc u
Biết rằng dữ liệu đầu vào có 1 lệnh duy nhất là MakeRoot và luôn ở dòng đầu tiên
· Dữ liệu: bao gồm các dòng, mỗi dòng có định dạng như mô tả ở trên, trong đó dòng cuối dùng ghi * (dấu hiệu kết thúc dữ liệu)
· Kết quả: ghi ra mỗi dòng kết quả của các lệnh CountLeaves và CountKChildren tương ứng đọc được từ đầu vào
Ví dụ:
Dữ liệu
MakeRoot 10
Insert 11 10
Insert 1 10
Insert 3 10
Insert 5 11
Insert 4 11
CountLeaves 4
CountKChildren 10 3
Insert 8 3
Insert 2 3
Insert 7 3
Insert 6 4
Insert 9 4
CountKChildren 10 3
CountLeaves 10
CountLeaves 3
*
Kết quả
1
1
2
7
3*/

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

int countLeaves(node* r){
    node* p = r->leftMostChild;
    if(p == NULL) return 1;
    int count = 0;
    while(p != NULL){
        count += countLeaves(p);
        p = p->rightSibling;
    }
    return count;
}

int CountKChildren(node* r, int k){
    if(r == NULL) return 0;
    int count = 0, child_count = 0;
    for(node* p = r->leftMostChild; p != NULL; p = p->rightSibling){
        child_count++;
        count += CountKChildren(p, k);
    }
    if(child_count == k) count++;
    return count;
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
        if(strcmp(queries, "CountLeaves") == 0){
            int id;
            scanf("%d", &id);
            printf("%d\n", countLeaves(find(id)));
        }
        if(strcmp(queries, "CountKChildren") == 0){
            int id, k;
            scanf("%d %d", &id, &k);
            printf("%d\n", CountKChildren(find(id), k));
        }
    }
}