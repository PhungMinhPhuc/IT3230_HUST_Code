/*Bài 3: (4đ) Thông tin về khách hàng của một ngân hàng bao gồm: Mã khách hàng (kiểu chuỗi, 7 ký tự, không có khách nào trùng mã nhau); Tên khách hàng (kiểu chuỗi, tối đa 20 ký tự, không chứa dấu cách); Hạng của khách hàng (kiểu chuỗi, nhận một trong các giá trị "VIP", "GOLD", "SILVER"). Số lượng khách hàng là rất lớn và luôn biến động. Khách hàng đến ngân hàng để thực hiện giao dịch phải xếp hàng. Thông thường, khách đến trước sẽ được phục vụ trước, đến sau sẽ được phục vụ sau. Thỉnh thoảng, lễ tân ngân hàng ra hỏi có khách nào là khách "VIP" thì mời vào phòng riêng để phục vụ.
Cho mô tả cấu trúc dữ liệu như sau:
typedef struct Customer{
    char id[8];
    char name[21];
    char level[7];
    struct Customer *next;
} Customer;
Hãy viết một chương trình C hoàn chỉnh, thực hiện những chức năng sau:
Create: tạo một danh sách liên kết rỗng.
Insert x y z: thêm một bản ghi vào cuối danh sách hiện tại, trong đó x là mã khách, y là tên khách và z là hạng của khách.
Print: hiển thị toàn bộ danh sách hiện tại ra màn hình theo đúng trật tự của danh sách, mỗi bản ghi trên một dòng, mỗi trường cách nhau bởi một dấu cách. Nếu danh sách rỗng thì hiển thị "EMPTY".
Vip: Xóa toàn bộ khách hàng "VIP" ra khỏi danh sách hiện tại.
Gold: hiển thị ra màn hình số lượng khách hàng "GOLD" hiện đang xếp hàng. Nếu không có khách nào hạng "GOLD" đang xếp hàng thì hiển thị "NO GOLD".
Serve: khách đứng đầu danh sách hiện tại được phục vụ, xóa bản ghi đó ra khỏi danh sách.
Chương trình kết thúc khi đọc được dấu "#".
Quan sát ví dụ minh họa sau:
INPUT:
Create
Print
Insert 1 John GOLD
Insert 2 David VIP
Insert 3 Mary SILVER
Insert 4 Joe GOLD
Print
Insert 6 Trump SILVER
Vip
Gold
Print
Serve
Print
#
OUTPUT:
EMPTY
1 John GOLD
2 David VIP
3 Mary SILVER
4 Joe GOLD
2
1 John GOLD
3 Mary SILVER
4 Joe GOLD
6 Trump SILVER
3 Mary SILVER
4 Joe GOLD
6 Trump SILVER*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 10000

typedef struct Customer{
    char id[8];
    char name[21];
    char level[7];
    struct Customer *next;
} Customer;

Customer* create(Customer* head){
    return NULL;
}

Customer* makenode(char id[], char name[], char level[]){
    Customer* newCustomer =(Customer*)malloc(sizeof(Customer));
    strcpy(newCustomer->id, id);
    strcpy(newCustomer->name, name);
    strcpy(newCustomer->level, level);
    newCustomer->next = NULL;
    return newCustomer;
}

Customer* insert(Customer* head, char id[], char name[], char level[]){
    Customer* newnode = makenode(id, name, level);
    if(head == NULL) head = newnode;
    else{
        Customer* p = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = newnode;
    }
    return head;
}

void printlist(Customer* head){
    if(head == NULL){
        printf("EMPTY\n");
        return;
    }
    Customer* p = head;
    while(p != NULL){
        printf("%s %s %s\n", p->id, p->name, p->level);
        p = p->next;
    }
}

Customer* deleteVip(Customer* head){
    Customer* p = head, *prev = NULL;
    while(p != NULL){
        if(strcmp(p->level, "VIP") == 0){
            if(p == head){
                head = p->next;
                p = head;
            }
            else {
                prev->next = p->next;
                p = prev->next;
            }
        }
        else{
            prev = p;
            p = prev->next;
        }
    }
    return head;
}

void printGold(Customer* head){
    Customer* p = head;
    int count = 0;
    while(p != NULL){
        if(strcmp(p->level, "GOLD") == 0) count++;
        p = p->next;
    }
    if(count == 0) printf("NO GOLD\n");
    else printf("%d\n", count);
}

Customer* serve(Customer* head){
    Customer* p = head;
    if(head == NULL) return NULL;
    head = p->next;
    free(p);
    return head;
}

int main(){
    Customer* head = NULL;
    char c[100];
    while(1){
        scanf("%s", c);
        if(strcmp(c, "#") == 0) break;
        else if(strcmp(c, "Create") == 0) head = create(head);
        else if(strcmp(c, "Insert") == 0){
            char id[8];
            char name[21];
            char level[7];
            scanf("%s %s %s", id, name, level);
            head = insert(head, id, name, level);
        }
        else if(strcmp(c, "Print") == 0) printlist(head);
        else if(strcmp(c, "Vip") == 0) head = deleteVip(head);
        else if(strcmp(c, "Gold") == 0) printGold(head);
        else if(strcmp(c, "Serve") == 0) head = serve(head);
    }
}