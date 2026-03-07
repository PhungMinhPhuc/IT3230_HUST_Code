/*Given a TEXT which consists of a sequence of words. Each word is defined to be a sequence of contiguous characters of the alphabet (a, ..., z, A, ..., Z) and digits (0, 1, ..., 9). Other special characters are considered as delimiters between words. 
Write a program to count the number of occurrences o(w) of each word w of the given TEXT.
Input
The TEXT (each word of the TEXT has length <= 20)

Output
Each line contains a word w and o(w) (separated by a SPACE). The words (printed to lines of the stdout) are sorted in a lexicographic order. 

Example
Input
abc  def abc 
abc abcd def 

Output 
abc 3
abcd 1
def 2
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 1000000

typedef struct node{
    char word[22];
    int occ;
    struct node* leftChild;
    struct node* rightChild;
} node;

node* root = NULL;
char text[maxlen];

int legal(char c){
    return ((c >= 'a' && c <='z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
}

void input(){
    char c[maxlen];
    while(fgets(c, sizeof(c), stdin)){
        c[strcspn(c, "\n\r")] = '\0';
        // if(strcmp(c, "*") == 0) break;
        strcat(text, c);
        strcat(text, " ");
    }
}

node* makenode(char word[]){
    node* p = (node*)malloc(sizeof(node));
    strcpy(p->word, word);
    p->occ = 1;
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}

node* addnode(node* root, char word[]){
    if(root == NULL) return makenode(word);
    int c = strcmp(root->word, word);
    if(c == 0){
        root->occ++;
        return root;
    }
    if(c > 0) root->leftChild = addnode(root->leftChild, word);
    else if(c < 0) root->rightChild = addnode(root->rightChild, word);
    return root;
}

void inorder(node* root){
    if(root == NULL) return;
    inorder(root->leftChild);
    printf("%s %d\n", root->word, root->occ);
    inorder(root->rightChild);
}

void slove(){
    int n = strlen(text), end = -1;
    char word[maxlen];
    for(int i=0; i<n; i++){
        if(legal(text[i])){
            end++;
            word[end] = text[i];
        }
        else {
            if(end != -1){
                word[end+1] = '\0';
                root = addnode(root, word);
            }
            end = -1;
        }
    }
    inorder(root);
}

int main(){
    input();
    slove();
}