/*A database contains a sequence of key k1, k2, ..., kn which are integers (1<=n<=100000). Perform a sequence of actions of two kinds:
· find k: find and return 1 if k exists in the database, and return 0, otherwise
· insert k: insert a key k into the database and return 1 if the insertion is successful (k does not exist in the database) and return 0 if the insertion is failed (k exists in the database)
Note that the value of any key is greater than or equal to 0 and less than or equal to 10^17.
Input
Two blocks of information. The first block contains a key of (k1,k2,...,kn) in each line. The first block is terminated with a line containing *. The second block is a sequence of actions of two finds described above: each line contains 2 string: cmd and k in which cmd = "find" or "insert" and k is the key (parameter of the action). The second block is terminated with a line containing ***. Note that the number of actions can be up to 100000.
Output
Each line contains the result (0 or 1) of the corresponding action.
Example
Input
4
5
2
*
find 3
insert 4
find 2
insert 3
find 3
***
Output
0
0
1
1
1*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define hash_size 1000000

typedef struct node{
    long long key;
    struct node* next;
} node;

node* hash_table[hash_size];

unsigned long long hash_funtion(long long key){
    return (unsigned long long) (key % hash_size);
}

void findnode(node* hash_table[], long long key){
    unsigned long long index = hash_funtion(key);
    node* p = hash_table[index];
    while(p != NULL){
        if(p->key == key){
            printf("1\n");
            return;
        }
        p = p->next;
    }
    printf("0\n");
    return;
}

void addnode(node* hash_table[], long long key){
    unsigned long long index = hash_funtion(key);
    node* p = hash_table[index];
    while(p != NULL){
        if(p->key == key){
            return;
        }
        p = p->next;
    }
    node* n = (node*)malloc(sizeof(node));
    n->key = key;
    n->next = hash_table[index];
    hash_table[index] = n;
    return;
}

void insert(node* hash_table[], long long key){
    unsigned long long index = hash_funtion(key);
    node* p = hash_table[index];
    while(p != NULL){
        if(p->key == key){
            printf("0\n");
            return;
        }
        p = p->next;
    }
    node* n = (node*)malloc(sizeof(node));
    n->key = key;
    n->next = hash_table[index];
    hash_table[index] = n;
    printf("1\n");
    return;
}

int main(){
    char c[50];
    while(fgets(c, sizeof(c), stdin)){
        c[strcspn(c, "\n\r")] = '\0';
        if(strcmp(c, "*") == 0) break;
        long long k;
        sscanf(c, "%lld", &k);
        addnode(hash_table, k);
    }
        while(fgets(c, sizeof(c), stdin)){
        c[strcspn(c, "\n\r")] = '\0';
        if(strcmp(c, "***") == 0) break;
        else if(strncmp(c, "find", 4) == 0){
            long long k;
            sscanf(c+4,"%lld", &k);
            findnode(hash_table, k);
        }
        else if(strncmp(c, "insert", 6) == 0){
            long long k;
            sscanf(c+6, "%lld", &k);
            insert(hash_table, k);
        }
    }
}