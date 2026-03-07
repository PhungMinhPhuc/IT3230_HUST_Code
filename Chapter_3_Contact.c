/*Viết chương trình quản lý danh bạ điện thoại di động. Mỗi liên lạc trong danh bạ chứa thông tin về họ tên, số điện thoại và email.
• Chương trình cần sử dụng một danh sách liên kết đơn để lưu trữ và quản lý các liên lạc với một số hàm sau:
• Thêm một liên lạc (phần tử) mới vào đầu danh sách.
• Thêm một liên lạc mới vào sau số liên lạc hiện tại trong danh sách
• Hiển thị nội dung danh bạ (danh sách)
• Xóa một số liên lạc: ở đầu danh sách; ở vị trí hiện tại,..
• Đảo ngược danh sách – Giải phóng bộ nhớ cấp phát cho danh sách.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxlen 10000

typedef struct contact{
    char name[20];
    char tell[12];
    char email[25];
    struct contact* next;
} contact;

void printlist(contact* h){
    contact* p = h;
    while(p != NULL){
        printf("%s %s %s\n", p->name, p->tell, p->email);
        p = p->next;
    }
}

contact* exsits(contact* head, contact u){
    contact* p = head;
    while(p != NULL){
        if(strcmp(p->name, u.name) == 0 && strcmp(p->tell, u.tell) == 0 && strcmp(p->email, u.email) == 0) return p;
        p = p->next;
    }
    return NULL;
}

contact* makecontact(contact key){
    contact* p = (contact*)malloc(sizeof(contact));
    strcpy(p->name, key.name);
    strcpy(p->tell, key.tell);
    strcpy(p->email, key.email);
    p->next = NULL;
    return p;
}

contact input(){
    contact temp;
    printf("Name: ");
    fgets(temp.name, sizeof(temp.name), stdin);
    temp.name[strcspn(temp.name, "\n\r")] = '\0';
    printf("Phone number: ");
    fgets(temp.tell, sizeof(temp.tell), stdin);
    temp.tell[strcspn(temp.tell, "\n\r")] = '\0';
    printf("Email: ");
    fgets(temp.email, sizeof(temp.email), stdin);
    temp.email[strcspn(temp.email, "\n\r")] = '\0';
    return temp;
}

contact* insertfirst(contact* head, contact key){
    contact* p = makecontact(key);
    if(head == NULL) return p;
    else{
        p->next = head;
        head = p;
        return head;
    }
}

contact* insertafter(contact* head, contact u, contact v){//Them v vao sau u
    contact* p = exsits(head, u);
    if(p == NULL) return head;
    contact* q = makecontact(v);
    if(p->next == NULL){
        p->next = q;
        return head;
    }
    q->next = p->next;
    p->next = q;
    return head;
}

// contact* prevnode(contact* head, contact* u){
//     contact* p = head;
//     while(p != NULL){
//         if(p->next == u) return p;
//         p = p->next;
//     }
//     return NULL;
// }

// contact* remove_first(contact* head, contact u){
//     contact* p = exsits(head, u);
//     if(p == NULL) return head;
//     contact* prev = prevnode(head, p);
//     if(prev == NULL){
//         head = head->next;
//         free(p);
//         return head;
//     }
//     prev->next = p->next;
//     free(p);
//     return head;
// }

contact* removenode(contact* head, contact u){
    contact* p = exsits(head, u);
    if(p == NULL) return head;
    if(p == head){
        head = head->next;
        free(p);
        return head;
    }
    contact* pre = head, *cur = head->next;
    while(cur != NULL){
        if(cur == p){
            pre->next = cur->next;
            free(p);
            break;
        }
        pre = cur;
        cur = cur->next;
    }
    return head;
}

contact* reverse(contact* head){
    contact* pre = NULL, * cur = head, * nex = NULL;
    while(cur != NULL){
        nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;
    }
    return pre;
}

void free_list(contact* head) {
    contact *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main(){
    int n;
    contact* head = NULL;
    contact* tail = NULL;
    printf("Numbers of people: ");
    scanf("%d", &n);
    getchar();
    for(int i=0; i<n; i++){
        contact* newnode = makecontact(input());
        if(head == NULL) head = tail = newnode;
        else{
            tail->next = newnode;
            tail = newnode;
        }
    }
    char c[maxlen];
    printf("***\n");
    while(1){
        if(!fgets(c, sizeof(c), stdin)) break;
        c[strcspn(c, "\n\r")] = '\0';
        if(strcmp(c, "#") == 0) break;
        else if(strcmp(c, "addFirst") == 0){
            head = insertfirst(head, input());
        }
        else if(strcmp(c, "addAfter") == 0){
            printf("Current: ");
            contact cur = input();
            printf("Contact after: ");
            contact after = input();
            head = insertafter(head, cur, after);
        }
        else if(strcmp(c, "remove") == 0){
            printf("Delete: ");
            contact del = input();
            head = removenode(head, del);
        }
        else if(strcmp(c, "reverse") == 0){
            head = reverse(head);
        }
    }
    printlist(head);
    free_list(head);
}