/*A database contains a sequence of key k1, k2, ..., kn which are strings (1<=n<=100000). Perform a sequence of actions of two kinds:
· find k: find and return 1 if k exists in the database, and return 0, otherwise
· insert k: insert a key k into the database and return 1 if the insertion is successful (k does not exist in the database) and return 0 if the insertion is failed (k exists in the database)
Note that the length of any key is greater than 0 and less than or equal to 50.
Input
Two blocks of information. The first block contains a key of (k1,k2,...,kn) in each line. The first block is terminated with a line containing *. The second block is a sequence of actions of two finds described above: each line contains 2 string: cmd and k in which cmd = find or insert and k is the key (parameter of the action). The second block is terminated with a line containing ***. Note that the number of actions can be up to 100000.
Output
Each line contains the result (0 or 1) of the corresponding action.
Example
Input
computer
university
school
technology
phone
*
find school
find book
insert book
find algorithm
find book
insert book
***
Output
1
0
1
0
1
0*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 100
#define hash_size 1000

typedef struct node{
    char key[maxlen];
    struct node* next;
} node;

node* hash_table[hash_size];

unsigned long long hash_funtion(char s[]){
    unsigned long long h = 0;
    while(*s){
        h = h*256 + *s++;
        h = h % hash_size;
    }
    return h;
}

void addnode(node* hash_table[], char key[]){
    unsigned long long index = hash_funtion(key);
    node* p = hash_table[index];
    while(p != NULL){
        if(strcmp(p->key, key) == 0) return;
        p = p->next;
    }
    node* n = (node*)malloc(sizeof(node));
    strcpy(n->key, key);
    n->next = hash_table[index];
    hash_table[index] = n;
}

void find(node* hash_table[], char key[]){
    unsigned long long index = hash_funtion(key);
    node* p = hash_table[index];
    while(p != NULL){
        if(strcmp(p->key, key) == 0){
            printf("1\n");
            return;
        }
        p = p->next;
    }
    printf("0\n");
}

void insert(node* hash_table[], char key[]){
    unsigned long long index = hash_funtion(key);
    node* p = hash_table[index];
    while(p != NULL){
        if(strcmp(p->key, key) == 0){
            printf("0\n");
            return;
        }
        p = p->next;
    }
    node* n = (node*)malloc(sizeof(node));
    strcpy(n->key, key);
    n->next = hash_table[index];
    hash_table[index] = n;
    printf("1\n");
}

int main(){
    char c[maxlen];
    while(fgets(c, sizeof(c), stdin)){
        c[strcspn(c, "\n\r")] = '\0';
        if(strcmp(c, "*") == 0) break;
        char k[maxlen];
        sscanf(c, "%s", k);
        addnode(hash_table, k);
    }
        while(fgets(c, sizeof(c), stdin)){
        c[strcspn(c, "\n\r")] = '\0';
        if(strcmp(c, "***") == 0) break;
        else if(strncmp(c, "find", 4) == 0){
            char k[maxlen];
            sscanf(c+4, "%s", k);
            find(hash_table, k);
        }
        else if(strncmp(c, "insert", 6) == 0){
            char k[maxlen];
            sscanf(c+6, "%s", k);
            insert(hash_table, k);
        }
    }
}