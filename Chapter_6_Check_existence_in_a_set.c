/*Cho dãy số nguyên A1, A2, . . . , An với mỗi số nguyên Ai kiểm tra xem có số Aj nào bằng Ai hay không với j<i.
Input
Dòng đầu chứa số n (1≤n≤100,000)
Dòng hai chứa n số nguyên A1, A2, ..., An (1≤Ai≤1000,000,000)
Output
Ghi ra n dòng, dòng thứ i in ra 1 nếu tồn tại Aj=Ai với j<i, ngược lại in ra 0.
Example
input
5
1 4 3 1 4
output
0
0
0
1
1*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 10000
#define hash_size 1000

typedef struct node{
    long long key;
    struct node* next;
} node;

node* hash_table[hash_size];

unsigned long long hash_funtion(long long k){
    return (k % hash_size);
}

void find(node* hash_table[], long long k){
    unsigned long long index = hash_funtion(k);
    node* p = hash_table[index];
    while(p != NULL){
        if(p->key == k){
            printf("1\n");
            return;
        }
        p = p->next;
    }
    node* m = (node*)malloc(sizeof(node));
    m->key = k;
    m->next = hash_table[index];
    hash_table[index] = m;
    printf("0\n");
}


int main(){
    int n, key;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &key);
        find(hash_table, key);
    }
}