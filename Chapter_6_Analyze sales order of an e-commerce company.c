/*Data about sales in an e-commerce company (the e-commerce company has several shops) consists a sequence of lines, each line (represents an order) has the following information:
            <CustomerID> <ProductID> <Price> <ShopID> <TimePoint>
in which the customer <CustomerID> buys a product <ProductID> with price <Price> at the shop <ShopID> at the time-point <TimePoint>
<CustomerID>: string of length from 3 to 10
<ProductID>: string of length from 3 to 10
<Price>: a positive integer from 1 to 1000
<ShopID>: string of length from 3 to 10
<TimePoint>: string representing time-point with the format HH:MM:SS (for example, 09:45:20 means the time-point 9 hour 45 minutes 20 seconds)

Perform a sequence of queries of following types:
?total_number_orders: return the total number of orders
?total_revenue: return the total revenue the e-commerce company gets
?revenue_of_shop <ShopID>: return the total revenue the shop <ShopID> gets 
?total_consume_of_customer_shop <CustomerID> <ShopID>: return the total revenue the shop <ShopID> sells products to customer <CustomerID> 
?total_revenue_in_period <from_time> <to_time>: return the total revenue the e-commerce gets of the period from <from_time> to <to_time> (inclusive)

Input
The input consists of two blocks of data:
The first block is the operational data, which is a sequence of lines (number of lines can be upto 100000), each line contains the information of a submission with above format 
The first block is terminated with a line containing the character #
The second block is the query block, which is a sequence of lines (number of lines can be upto 100000), each line is a query described above
The second block is terminated with a line containing the character #

Output
Write in each line, the result of the corresponding query 

Example
Input
C001 P001 10 SHOP001 10:30:10
C001 P002 30 SHOP001 12:30:10
C003 P001 40 SHOP002 10:15:20
C001 P001 80 SHOP002 08:40:10
C002 P001 130 SHOP001 10:30:10
C002 P001 160 SHOP003 11:30:20
#
?total_number_orders
?total_revenue
?revenue_of_shop SHOP001
?total_consume_of_customer_shop C001 SHOP001 
?total_revenue_in_period 10:00:00 18:40:45
#
Output 
6
450
170
40
370*/


/*Cách 1: Sort and BS vô phương cứu chữa*/
// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// #include <stdlib.h>

// #define maxlen 100001

// typedef struct  {
//     char customerID[11];
//     char productID[11];
//     int price;
//     char shopID[11];
//     char time[10];
// } order;

// order data[maxlen]; 

// void swap(order *a, order *b){
//     order temp = *a;
//     *a = *b;
//     *b = temp;
// }

// int partitionShop(order data[], int left, int right){
//     int i = left, j = right+1;
//     char pivot[11];
//     strcpy(pivot, data[left].shopID);
//     while(i < j){
//         i++;
//         while(i <= right && strcmp(pivot, data[i].shopID) > 0) i++;
//         j--;
//         while(j >= left && strcmp(pivot, data[j].shopID) < 0) j--;
//         swap(&data[i], &data[j]);
//     }
//     swap(&data[i], &data[j]);
//     swap(&data[left], &data[j]);
//     return j;
// }

// void quicksortShop(order data[], int left, int right){
//     int pivot;
//     if(left < right){
//         pivot = partitionShop(data, left, right);
//         if(left < pivot) quicksortShop(data, left, pivot-1);
//         if(right > pivot) quicksortShop(data, pivot+1, right);
//     }

// }

// int lowerShop(order data[], int start, int end, char shop[]){
//     int l = start, r = end;
//     while(l < r){
//         int m = (l+r)/2;
//         if(strcmp(data[m].shopID, shop) < 0) l = m+1;
//         else r = m;
//     }
//     return l;
// }

// int upperShop(order data[], int start, int end, char shop[]){
//     int l = start, r = end;
//     while(l < r){
//         int m = (l+r)/2;
//         if(strcmp(data[m].shopID, shop) <= 0) l = m+1;
//         else r = m;
//     }
//     return l;
// }

// int revenue_of_shop(order data[], char shop[], int n){
//     int shopRevenue = 0;
//     for(int i=lowerShop(data, 0, n, shop); i<upperShop(data, 0, n, shop); i++){
//         shopRevenue += data[i].price;
//     }
//     return shopRevenue;
// }

// int total_consume_of_customer_shop(order data[], char customer[], char shop[], int n){
//     int shopRevenue = 0;
//     for(int i=lowerShop(data, 0, n, shop); i<upperShop(data, 0, n, shop); i++){
//         if(strcmp(customer, data[i].customerID) == 0){
//             shopRevenue += data[i].price;
//         }
//     }
//     return shopRevenue;
// }

// // int total_consume_of_customer_shop(order data[], char customer[], char shop[], int n){
// //     int shopRevenue = 0;
// //     for(int i=0; i<n; i++){
// //         if(strcmp(customer, data[i].customerID) == 0 && strcmp(shop, data[i].shopID) == 0){
// //             shopRevenue += data[i].price;
// //         }
// //     }
// //     return shopRevenue;
// // }

// int partitionTime(order data[], int left, int right){
//     int i = left, j = right+1;
//     char pivot[11];
//     strcpy(pivot, data[left].time);
//     while(i < j){
//         i++;
//         while(i <= right && strcmp(pivot, data[i].time) > 0) i++;
//         j--;
//         while(j >= left && strcmp(pivot, data[j].time) < 0) j--;
//         swap(&data[i], &data[j]);
//     }
//     swap(&data[i], &data[j]);
//     swap(&data[left], &data[j]);
//     return j;
// }

// void quicksortTime(order data[], int left, int right){
//     int pivot;
//     if(left < right){
//         pivot = partitionTime(data, left, right);
//         if(left < pivot) quicksortTime(data, left, pivot-1);
//         if(right > pivot) quicksortTime(data, pivot+1, right);
//     }

// }

// int lowerTime(order data[], int start, int end, char startTime[]){
//     int l = start, r = end;
//     while(l < r){
//         int m = (l+r)/2;
//         if(strcmp(data[m].time, startTime) < 0) l = m+1;
//         else r = m;
//     }
//     return l;
// }

// int upperTime(order data[], int start, int end, char endTime[]){
//     int l = start, r = end;
//     while(l < r){
//         int m = (l+r)/2;
//         if(strcmp(data[m].time, endTime) <= 0) l = m+1;
//         else r = m;
//     }
//     return l;
// }

// int total_revenue_in_period_time(order data[], char start[], char end[], int n){
//     int timeRevenue = 0;
//     for(int i=lowerTime(data, 0, n, start); i<upperTime(data, 0, n, end); i++){
//         timeRevenue += data[i].price;
//     }
//     return timeRevenue;
// }

// // int total_revenue_in_period_time(order data[], char start[], char end[], int n){
// //     int timeRevenue = 0;
// //     for(int i=0; i<n; i++){
// //         if(strcmp(start, data[i].time) <= 0 && strcmp(end, data[i].time) >= 0){
// //             timeRevenue += data[i].price;
// //         }
// //     }
// //     return timeRevenue;
// // }

// int main(){
//     int count = 0; int revenue = 0, foundshop = 0, foundtime = 0;
//     char c[maxlen];
//     while(1){
//         if(!fgets(c, sizeof(c), stdin)) break;
//         c[strcspn(c, "\n\r")] = '\0';
//         if(strcmp(c, "#") == 0) break;
//         sscanf(c, "%s %s %d %s %s", data[count].customerID, data[count].productID, &data[count].price, data[count].shopID, data[count].time);
//         revenue += data[count].price;
//         count++;
//     }
//     while(1){
//         if(!fgets(c, sizeof(c), stdin)) break;
//         c[strcspn(c, "\n\r")] = '\0';
//         if(strcmp(c, "#") == 0) break;
//         else if(strcmp(c, "?total_number_orders") == 0) printf("%d\n", count);
//         else if(strcmp(c, "?total_revenue") == 0) printf("%d\n", revenue);
//         else if(strncmp(c, "?revenue_of_shop", 16) == 0){
//             if(!foundshop){
//                 quicksortShop(data, 0, count-1);
//                 foundshop = 1;
//             }
//             char shop[11];
//             sscanf(c+16, "%s", shop);
//             printf("%d\n", revenue_of_shop(data, shop, count));
//         }
//         else if(strncmp(c, "?total_consume_of_customer_shop", 31) == 0){
//             if(!foundshop){
//                 quicksortShop(data, 0, count-1);
//                 foundshop = 1;
//             }
//             char customer[11], shop[11];
//             sscanf(c+31, "%s %s", customer, shop);
//             printf("%d\n", total_consume_of_customer_shop(data, customer, shop, count));
//         }
//         else if(strncmp(c, "?total_revenue_in_period", 24) == 0){
//             if(!foundtime){
//                 quicksortTime(data, 0, count-1);
//                 foundtime = 1;
//             }
//             char start[11], end[11];
//             sscanf(c+24, "%s %s", start, end);
//             printf("%d\n", total_revenue_in_period_time(data, start, end, count));
//         }
//     }
//     // quicksortTime(data, 0, count-1);
//     // for(int i=0; i<count; i++) printf("%s %s %d %s %s\n", data[i].customerID, data[i].productID, &data[i].price, data[i].shopID, data[i].time);
// }


/*Cách 2: Hash*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 100001
#define hash_table_size 10000

typedef struct  {
    char customerID[11];
    char productID[11];
    int price;
    char shopID[11];
    int time;
} order;

order data[maxlen]; 

typedef struct node {
    char key[25];
    int value;
    struct node* next; 
} node;

node* shop_table[hash_table_size];
node* customer_shop_table[hash_table_size];

unsigned int hash(char *s){
    unsigned int h = 0;
    while(*s){
        h = h*31 + *s++;
        h = h % hash_table_size;
    }
    return h;
}

void addnode(node* table[], char key[], int value){
    unsigned int idx = hash(key);
    node* p = table[idx];
    while(p != NULL){
        if(strcmp(p->key, key) == 0){
            p->value += value;
            return;
        }
        p = p->next;
    }
    node* n = (node*)malloc(sizeof(node));
    strcpy(n->key, key);
    n->value = value;
    n->next = table[idx];
    table[idx] = n;
}

int get(node* table[], char* key){
    unsigned int idx = hash(key);
    node* p = table[idx];
    while(p != NULL){
        if(strcmp(p->key, key) == 0){
            return p->value;
        }
        p = p->next;
    }
    return 0;
}

int convert_time_to_sec(char time[]){
    int h, m, s;
    sscanf(time, "%d:%d:%d", &h, &m, &s);
    return h*3600 + m*60 + s;
}

void swap(order *a, order *b){
    order temp = *a;
    *a = *b;
    *b = temp;
}

int partitionTime(order data[], int left, int right){
    int i = left, j = right + 1;
    int pivot = data[left].time;
    while(i < j){
        i++;
        while(i <= right && pivot > data[i].time) i++;
        j--;
        while(j >= left && pivot < data[j].time) j--;
        swap(&data[i], &data[j]);
    }
    swap(&data[i], &data[j]);
    swap(&data[left], &data[j]);
    return j;
}

void quicksortTime(order data[], int left, int right){
    int pivot;
    if(left < right){
        pivot = partitionTime(data, left, right);
        if(left < pivot) quicksortTime(data, left, pivot - 1);
        if(right > pivot) quicksortTime(data, pivot + 1, right);
    }
}

int lowerTime(order data[], int start, int end, int startTime){
    int l = start, r = end;
    while(l < r){
        int m = (l+r)/2;
        if(data[m].time - startTime < 0) l = m+1;
        else r = m;
    }
    return l;
}

int upperTime(order data[], int start, int end, int endTime){
    int l = start, r = end;
    while(l < r){
        int m = (l+r)/2;
        if(data[m].time - endTime <= 0) l = m+1;
        else r = m;
    }
    return l;
}

int total_revenue_in_period_time(order data[], int prefix[], int start, int end, int n){
    int left = lowerTime(data, 0, n, start), right = upperTime(data, 0, n, end);
    return prefix[right-1] - prefix[left-1];
}

int main(){
    int count = 0; int revenue = 0;
    char c[maxlen];
    while(1){
        if(!fgets(c, sizeof(c), stdin)) break;
        c[strcspn(c, "\n\r")] = '\0';
        if(strcmp(c, "#") == 0) break;
        char timehms[11];
        sscanf(c, "%s %s %d %s %s", data[count].customerID, data[count].productID, &data[count].price, data[count].shopID, timehms);
        data[count].time = convert_time_to_sec(timehms);
        revenue += data[count].price;
        addnode(shop_table, data[count].shopID, data[count].price);
        char key[23];
        sprintf(key, "%s_%s", data[count].customerID, data[count].shopID);
        addnode(customer_shop_table, key, data[count].price);
        count++;
    }
    quicksortTime(data, 0, count-1);
    int prefix[maxlen];
    prefix[0] = data[0].price;
    for(int i=1; i<count; i++){
        prefix[i] = prefix[i-1] + data[i].price;
    }
    while(1){
        if(!fgets(c, sizeof(c), stdin)) break;
        c[strcspn(c, "\n\r")] = '\0';
        if(strcmp(c, "#") == 0) break;
        else if(strcmp(c, "?total_number_orders") == 0) printf("%d\n", count);
        else if(strcmp(c, "?total_revenue") == 0) printf("%d\n", revenue);
        else if(strncmp(c, "?revenue_of_shop", 16) == 0){
            char shop[11];
            sscanf(c+16, "%s", shop);
            printf("%d\n", get(shop_table, shop));
        }
        else if(strncmp(c, "?total_consume_of_customer_shop", 31) == 0){
            char customer[11], shop[11];
            sscanf(c+31, "%s %s", customer, shop);
            char key[25];
            sprintf(key, "%s_%s", customer, shop);
            printf("%d\n", get(customer_shop_table, key));
        }
        else if(strncmp(c, "?total_revenue_in_period", 24) == 0){
            char starthms[11], endhms[11];
            sscanf(c+24, "%s %s", starthms, endhms);
            int start = convert_time_to_sec(starthms), end = convert_time_to_sec(endhms);
            printf("%d\n", total_revenue_in_period_time(data, prefix, start, end, count));
        }
    }
    // quicksortTime(data, 0, count-1);
    // for(int i=0; i<count; i++) printf("%s %s %d %s %d\n", data[i].customerID, data[i].productID, data[i].price, data[i].shopID, data[i].time);
    // for(int i=0; i<count; i++) printf("%d\n", prefix[i]);
}