// //Sinh xau nhi phan nhap vao co do dai n + khong co 2 so 1 canh nhau

// // #include <stdio.h>

// // #define maxlen 10000

// // int n, x[maxlen];

// // void print(){
// //     for(int i=1; i<=n; i++){
// //         printf("%d ", x[i]);
// //     }
// //     printf("\n");
// // }

// // void try(int k){
// //     for(int i=0; i<=1; i++){
// //         x[k] = i;
// //         if(k > 1 && x[k-1] == 1 && x[k] == 1) continue;
// //         if(k == n) print();
// //         else try(k+1);
// //     }
// // }

// // int main(){
// //     scanf("%d", &n);
// //     try(1);
// // }


// //Chen them 1 phan tu vao vi tri thu i

// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// #include <stdlib.h>

// #define maxlen 10000

// typedef struct node{
//     int key;
//     struct node* next;
// } node;

// node* makenode(int v){
//     node* p = (node*)malloc(sizeof(node));
//     p->key = v;
//     p->next = NULL;
//     return p;
// }

// node* exists_key(node*head, int key){
//     node* p = head;
//     while(p != NULL){
//         if(p->key == key) return p;
//         p = p->next;
//     }
//     return NULL;
// }

// int exists(node* head, node* u){
//     node* p = head;
//     while(p != NULL){
//         if(u == p) return 1;
//         p = p->next;
//     }
//     return 0;
// }

// void printlist(node* p){
//     while(p != NULL){
//         printf("%d ", p->key);
//         p = p->next;
//     }
// }

// node* findlastnode(node* head){
//     node* p = head;
//     while(p != NULL){
//         if(p->next == NULL) return p;
//         p = p->next;
//     }
//     return NULL;
// }

// node* insertlast(node* head, int v){
//     node* new_node = makenode(v);
//     if(head == NULL) return new_node;
//     else{
//         node* lastnode = findlastnode(head);
//         lastnode->next = new_node;
//         return head;
//     }
// }

// node* insertfirst(node* head, int v){
//     node* new_node = makenode(v);
//     if(head == NULL) return new_node;
//     else{
//         new_node->next = head;
//         head = new_node;
//         return head;
//     }
// }

// node* insertNode(node* head, int v, int i, int n){
//     node* new_node = makenode(v);
//     node* p = head;
//     int k = 1;
//     if(i <= 0) insertfirst(head, v);
//     else if(i > n) insertlast(head, v);
//     else{
//         while(k != i){
//             p = p->next;
//             k++;
//         }
//         new_node->next = p->next;
//         p->next = new_node;
//         return head;
//     }
// }

// node* prevnode(node* head, node* u){
//     node* p = head;
//     while(p != NULL){
//         if(p->next == u) return p;
//         p = p->next;
//     }
//     return NULL;
// }

// node* insertbefore(node* head, node* u, int v){
//     node* p = prevnode(head, u);
//     if(p == NULL && u != NULL) return head;
//     node* q = makenode(v);
//     if(u == NULL){
//         if(head == NULL) return q;
//         q->next = head;
//         return q;
//     }
//     q->next = u;
//     p->next = q;
//     return head;
// }

// node* insertafter(node* head, node* u, int v){
//     if(exists(head, u) == 0) return head;
//     node* q = makenode(v);
//     if(u->next == NULL){
//         u->next = q;
//         return head;
//     }
//     q->next = u->next;
//     u->next = q;
//     return head;
// }

// node* removenode_recursive(node* head, node* u){
//     if(head == NULL || u == NULL) return head;
//     if(head == u){
//         head = head->next;
//         free(u);
//         return head;
//     }
//     else head->next = removenode_recursive(head->next, u);
// }

// node* removenode(node* head, node* u){
//     if(head == NULL || u == NULL) return head;
//     if(head == u){
//         head = head->next;
//         free(u);
//         return head;
//     }
//     node* pre = head;
//     node* cur = head->next;
//     while(cur != NULL){
//         if(cur == u){
//             pre->next = cur->next; //u->next
//             free(u);
//             break;
//         }
//         pre = cur;
//         cur = cur->next;
//     }
//     return head;
// }

// node* reverse(node* head){
//     node* pre = NULL,* fol = NULL;
//     node* cur = head;
//     while(cur != NULL){
//         fol = cur->next;
//         cur->next = pre;
//         pre = cur;
//         cur = fol;
//     }
//     head = pre;
//     return head;
// }

// int main(){
//     int n;
//     scanf("%d", &n);
//     node* head = NULL;
//     node* tail = NULL;
//     for(int i=0; i<n; i++){
//         int c;
//         scanf("%d", &c);
//         node* new_node = makenode(c);
//         if(head == NULL) head = tail = new_node;
//         else{
//             tail->next = new_node;
//             tail = new_node;
//         }
//     }
//     char x[100];
//     getchar();
//     while(1){
//         if(!fgets(x, sizeof(x), stdin)) break;
//         x[strcspn(x, "\n\r")] = '\0';
//         if(strcmp(x, "#") == 0) break;
//         if(strncmp(x, "addlast ", 8) == 0){
//             int m;
//             sscanf(x+8, "%d", &m);
//             if(exists_key(head, m) == NULL) head = insertlast(head, m);
//         }
//         else if(strncmp(x, "addfirst ", 9) == 0){
//             int m;
//             sscanf(x+9, "%d", &m);
//             if(exists_key(head, m) == NULL) head = insertfirst(head, m);
//         }
//         else if(strncmp(x, "addafter ", 9) == 0){
//             int m, k;
//             sscanf(x+9, "%d %d", &k, &m);
//             node* temp = exists_key(head, m);
//             node* tempk = exists_key(head, k);
//             if(temp != NULL && tempk == NULL) head = insertafter(head, temp, k);
//         }
//         else if(strncmp(x, "addbefore ", 10) == 0){
//             int m, k;
//             sscanf(x+10, "%d %d", &k, &m);
//             node* temp = exists_key(head, m);
//             node* tempk = exists_key(head, k);
//             if(temp != NULL && tempk == NULL) head = insertbefore(head, temp, k);
//         }
//         else if(strncmp(x, "remove ", 7) == 0){
//             int m;
//             sscanf(x+7, "%d", &m);
//             node* temp = exists_key(head, m);
//             head = removenode(head, temp);
//         }
//         else if (strcmp(x, "reverse") == 0){
//             head = reverse(head);
//         }
//         else if(strncmp(x, "AddNodevi ", 10) == 0){
//             int v, i;
//             sscanf(x+10, "%d %d", &v, &i);
//             head = insertNode(head, v, i, n);
//         }
//     }
//     printlist(head);
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100000

typedef struct node_t{
    int data;
    struct node_t* next;
}node;

node* create_node(int a){
    node* n=(node*)malloc(sizeof(node));
    n->data=a;
    n->next=NULL;
    return n;
}

int check[N+1]={0};
node* head=NULL;
node* tail=NULL;

void push_head(int a){
    if(a<0) return;
    if(check[a]) return;
    check[a]=1;
    if(head==NULL){
        head=create_node(a);
        tail=head;
        return;
    }

    node* n=create_node(a);
    n->next=head;
    head=n;
}

void push_tail(int a){
    if(a<0) return;
    if(check[a]) return;
    check[a]=1;
    if(tail==NULL){
        head=tail=create_node(a);
        return;
    }

    node* n=create_node(a);
    tail->next=n;
    tail=n;
}

void print_list(int a){
    if(head == NULL) printf("EMPTY\n");
    if(a){
        node* tmp=head;
        while(tmp!=NULL){
            if(tmp->data%2==0) printf("%d ",tmp->data);
            tmp=tmp->next;
        }
        tmp=head;
        while(tmp!=NULL){
            if(tmp->data%2==1) printf("%d ",tmp->data);
            tmp=tmp->next;
        }
    }
    else{
        node* tmp=head;
        while(tmp!=NULL){
            printf("%d ",tmp->data);
            tmp=tmp->next;
        }
    }
}


int main()
{
    memset(check,0,sizeof(check));
    char queue[20];
    int a;
    while(1){
        scanf("%s",queue);
        if(!strcmp(queue,"Print")){
            scanf("%d",&a);
            print_list(a);
            break;
        }
        else if(!strcmp(queue,"InsertHead")){
            scanf("%d",&a);
            push_head(a);
        }
        else if(!strcmp(queue,"InsertTail")){
            scanf("%d",&a);
            push_tail(a);
        }
    }
    return 0;
}
