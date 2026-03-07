/*Given a family tree represented by child-parent (c,p) relations in which c is a child of p. Perform queries about the family tree:
descendants <name>: return number of descendants of the given <name>
generation <name>: return the number of generations of the descendants of the given <name>

Note that: the total number of people in the family is less than or equal to 10^4
Input
Contains two blocks. The first block contains information about child-parent, including lines (terminated by a line containing ***), each line contains: <child> <parent> where <child> is a string represented the name of the child and <parent> is a string represented the name of the parent. The second block contains lines (terminated by a line containing ***), each line contains two string <cmd> and <param> where <cmd> is the command (which can be descendants or generation) and <param> is the given name of the person participating in the  query.
Output
Each line is the result of a corresponding query.
Example
Input
Peter Newman
Michael Thomas
John David
Paul Mark
Stephan Mark
Pierre Thomas
Mark Newman
Bill David
David Newman
Thomas Mark
***
descendants Newman
descendants Mark
descendants David
generation Mark
***
Output
10
5
2
2*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 1000

typedef struct node{
    char name[maxlen];
    struct node * leftMostChild;
    struct node * rightSibling;
} node;

node* nodes[maxlen];
int n = 0;

node* find(char* name){
    for(int i=0; i<n; i++){
        if(strcmp(name, nodes[i]->name) == 0) return nodes[i]; 
    }
    return NULL;
}

node* addnode(char* name){
    node* p = (node*)malloc(sizeof(node));
    strcpy(p->name, name);
    p->rightSibling = NULL;
    p->leftMostChild = NULL;
    nodes[n] = p;
    n++;
    return p;
}

node* makeChildParent(node* child, node* parent){
    child->rightSibling = parent->leftMostChild;
    parent->leftMostChild = child;
}

//Dem so con chau
int count(node* root){
    if(root == NULL) return 0;
    int c = 1;
    for(node* p = root->leftMostChild; p != NULL; p = p->rightSibling){
        c += count(p);
    }
    return c;
}

int height(node* root){
    if(root == NULL) return 0;
    int maxH = 0;
    for(node* p = root->leftMostChild; p != NULL; p = p->rightSibling){
        int h = height(p);
        if(maxH < h) maxH = h;
    }
    return maxH + 1;
}

void buildTree(){
    char childName[maxlen], parentName[maxlen];
    while(1){
        scanf("%s", childName);
        if(strcmp(childName, "***") == 0) break;
        scanf("%s", parentName);
        node* childNode = find(childName);
        if(childNode == NULL) childNode = addnode(childName);
        node* parentNode = find(parentName);
        if(parentNode == NULL) parentNode = addnode(parentName);
        makeChildParent(childNode, parentNode);
    }
}

void performQueries(){
    char queries[maxlen], name[maxlen];
    while(1){
        scanf("%s", queries);
        if(strcmp(queries, "***") == 0) break;
        scanf("%s", name);
        if(strcmp(queries, "descendants") == 0){
            node* p = find(name);
            printf("%d\n", count(p) - 1);
        }
        if(strcmp(queries, "generation") == 0){
            node* p = find(name);
            printf("%d\n", height(p) - 1);
        }
    }
}

int main(){
    buildTree();
    performQueries();
}