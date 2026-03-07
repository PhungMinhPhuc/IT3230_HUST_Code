/*Given a binary search tree T in which the keys of nodes are distinct positive integers. The sequence of keys visited when traversing T in a pre-order principle is a1, a2, ..., an. Compute the sequence of keys visited when traversing T in a post-order principal.

Input
Line 1: contains a positive integer n (1 <= n <= 50000)
Line 2: contains a sequence of distinct positive integer a1, a2, ..., an (1 <= ai <= 1000000)

Output
Write the sequence of keys visited when traversing T in a post-order principal (elements are separated by a SPACE character) if the binary search tree exists, and write NULL, otherwise.

Example
Input
11
10 5 2 3 8 7 9 20 15 18 40
Output
3 2 7 9 8 5 18 15 40 20 10


Example
Input 
11
10 5 2 3 8 7 9 20 15 18 4
Output 
NULL */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 100000
int n, pre[maxlen], post[maxlen], k = 0;

int checkPreorder(int pre[]){
    int index;
    for(int i=0; i<n; i++){
        if(pre[i] > pre[0]){
            index = i;
            break;
        }
    }
    for(int i=index+1; i<n; i++){
        if(pre[0] > pre[i]) return 0;
    }
    return 1;
}

void PreToPost(int pre[], int left, int right){
    if(left >= right) return;
    int id = 0;
    for(id=left+1; id<right; id++){
        if(pre[id] > pre[left]) break;
    }
    PreToPost(pre, left + 1, id);
    PreToPost(pre, id, right);
    post[k++] = pre[left];
    return;
}



int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &pre[i]);
    if(checkPreorder(pre) == 1){
        PreToPost(pre, 0, n);
        for(int i=0; i<n; i++) printf("%d ", post[i]);
    }
    else printf("NULL");
}