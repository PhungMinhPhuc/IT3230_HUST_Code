/*A polynomial is stored in a linked list:
    Each term is stored in a node of the list with 2 fields: coefficient and exponent
    Nodes are always sorted in a decreasing order of exponents 
    No two nodes have the same value of exponents
Each polynomial has an identifier which is a positive integer from 1 to 10000
Given a list of commands over polynomials below:
    Create <id>: create a polynomial with identifier <pol_id> if this polynomial does not exists, otherwise, do nothing
    AddTerm <id> <coef> <exp>: Add a term with coefficient <coef> and exponent <exp> to the polynomial having identifier <id> (create a new polynomial if it does not exist)
    EvaluatePoly <id> <variable_value>: Evaluate and print the value of the polynomial having identifier <id> and <variable_value> is the value of the variable (print 0 if the polynomial does not exist) 
    AddPoly <id1> <id2> <result_id>: Perform the addition operation over two polynomials <pol_id1> and <id2>. The resulting polynomial will have identifier <result_id> (if the polynomial <result_id> exists, then overrides the existing polynomial)
    PrintPoly <id>: print the polynomial <id> (if it exists) to stdout under the form <c_1> <e_1> <c_2> <e_2> ... (sequence of pairs of (coefficient, exponent) of terms of the polynomial in a decreasing order of exponents)
    Destroy <id>: destroy the polynomial having identifier <id>

Input
Each line contains a command described above (terminated by a line containing *)
Output
Each line contains the information printed out by the PrintPoly and EvaluatePoly above

Example
Input
AddTerm 1 3 2
AddTerm 1 4 0
AddTerm 1 6 2
AddTerm 2 3 2
AddTerm 2 7 5
PrintPoly 1
PrintPoly 2
AddPoly 2 1 3
PrintPoly 3
EvaluatePoly 2 1
*
Output
9 2 4 0
7 5 3 2
7 5 12 2 4 0
10    */

/*Cách 1: List of linked list*/
// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// #include <stdlib.h>

// typedef struct polynomial{
//     int id;
//     struct polynomial* next;
// } polynomial;

// typedef struct term{
//     int coef;
//     int exp;
//     struct term* next;
// } term;

// polynomial* findpoly(polynomial* head_mana, int id){
//     polynomial* p = head_mana;
//     while(p != NULL){
//         if(p->id == id) return p;
//         p = p->next;
//     }
//     return NULL;
// }

// polynomial* makepoly(int id){
//     polynomial* p = (polynomial*)malloc(sizeof(polynomial));
//     p->id = id;
//     p->next = NULL;
//     return p;
// }

// term* makenode(int coef, int exp){
//     term* p =(term*)malloc(sizeof(term));
//     p->coef = coef;
//     p->exp = exp;
//     p->next = NULL;
//     return p;
// }

// polynomial* create(polynomial* head_mana, int id){
//     term* head1 = findpoly(head_mana, id);
//     if(head1 != NULL) return head1;
//     term* head2 = makepoly(id);
//     return head2;
// }

// term* addterm(polynomial* head_mana, int id, int coef, int exp){
//     term* head = create(head_mana, id);
//     term* p = head, *prev = NULL;
//     while(p != NULL && p->exp > exp){  
//         prev = p;
//         p = p->next;
//     }
//     if(p->exp == exp){
//         p->coef += coef;
//         if(p->coef == 0){
//             if(prev == NULL) head = p->next;
//             else prev->next = p->next;
//             free(p);
//         }
//     }
//     else{
//         term* newnode = makenode(coef, exp);
//         newnode->next = prev->next;
//         prev->next = newnode; 
//     }
// }

// void printpoly(term* head){
//     term* p = head;
//     while(p != NULL){
//         printf("%dx^%d + ", p->coef, p->exp);
//         p = p->next;
//     }
// }

// void printlist(polynomial* headmana){
//     polynomial*p = headmana;
//     while(p != NULL){
//         printf("%d = ", p->id);
//         printpoly(p);
//         printf("\n");
//     }
// }

// int main(){
//     polynomial* head_mana;
//     char c[50];
//     while(1){
//         if(!fgets(c, sizeof(c), stdin)) break;
//         c[strcspn(c, "\n\r")] = '\0';
//         if(strcmp(c, "#") == 0) break;
//         if(strncmp(c, "Create ", 7) == 0){
//             int id;
//             sscanf(c+7, "%d", &id);
//             head_mana = create(head_mana, id);
//         }
//         else if(strncmp(c, "AddTerm ", 8) == 0){
//             int id, coef, exp;
//             sscanf(c+8, "%d %d %d", &id, &coef, &exp);
//             head_mana = addterm(head_mana, id, coef, exp);
//         }
//     }
//     printlist(head_mana);
// }

/*Cách 2: Dùng mảng*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define maxlen 100001

typedef struct term{
    int coef;
    int exp;
    struct term* next;
} term;

term* polyid[maxlen];

void printlist(){
    for(int i=0; i<maxlen; i++){
        if(polyid[i] != NULL){
            printf("%d = ", i);
            term* p = polyid[i];
            while(p != NULL){
                printf("%dx^%d + ", p->coef, p->exp);
                p = p->next;
            }
            printf("\n");
        }
    }
}

term* makenode(int coef, int exp){
    term* p = (term*)malloc(sizeof(term));
    p->coef = coef;
    p->exp = exp;
    p->next = NULL;
    return p;
}

void create(int id){
    if(polyid[id] == NULL) polyid[id] = makenode(0, 0);
}

term* addterm(int id, int coef, int exp){
    term* head = polyid[id];
    if(head == NULL){
        term* p = makenode(coef, exp);
        return p;
    }
    else{
        term* p = polyid[id];
        term* prev = NULL;
        while(p != NULL && p->exp > exp){  
            prev = p;
            p = p->next;
        }
        if(p != NULL && p->exp == exp){
            p->coef += coef;
            if(p->coef == 0){
                if(prev == NULL) polyid[id] = p->next;
                else prev->next = p->next;
                free(p);
            }
            return polyid[id];
        }
        term* q = makenode(coef, exp);
        if(prev == NULL){
            q->next = polyid[id];
            polyid[id] = q;
        } 
        else{
            q->next = p;
            prev->next = q;
        }
        return polyid[id];
    }
}

void EvaluatePoly(int id, int val){
    if(polyid[id] == NULL) printf("0\n");
    else{
        term* head = polyid[id];
        term* p = head;
        int fx = 0;
        while(p != NULL){
            fx += p->coef * pow(val, p->exp);
            p = p->next;
        }
        printf("%d\n", fx);
    }
}

term* insertLast(term* head, int coef, int exp){
    term* newnode = makenode(coef, exp);
    if(head == NULL) return newnode;
    term* p = head;
    while(p != NULL){
        if(p->next == NULL){
            p->next = newnode;
            return head;
        }
        p = p->next;
    }
    return NULL;
}

term* copypoly(term* from, term* to){
    term* p = from;
    while(p != NULL){
        to = insertLast(to, p->coef, p->exp);
        to = to->next;
    }
    return to;
}

void AddPoly(int id1, int id2, int resid){
    if(polyid[id1] == NULL && polyid[id2] == NULL) polyid[resid] = NULL;
    else if(polyid[id1] == NULL || polyid[id2] == NULL){
        polyid[resid] = NULL;
        if(polyid[id1] == NULL) polyid[resid] = copypoly(polyid[resid], polyid[id2]);
        else polyid[resid] = copypoly(polyid[resid], polyid[id1]);
    }
    else{
        polyid[resid] = NULL;
        term* u = polyid[id1], * v = polyid[id2], * res = polyid[resid];
        while(u != NULL || v != NULL){
            if(v == NULL || (u != NULL && u->exp > v->exp)){
                res = insertLast(res, u->coef, u->exp);
                u = u->next;
            } 
            else if(u == NULL || (v != NULL && v->exp > u->exp)){
                res = insertLast(res, v->coef, v->exp);
                v = v->next;
            }
            else{
                if(u->coef + v->coef != 0) res = insertLast(res, u->coef + v->coef, u->exp); // or v->exp
                u = u->next;
                v = v->next;
            }
        }
        polyid[resid] = res;
    }
}

void printpoly(int id){
    if(polyid[id] != NULL){
        term* p = polyid[id];
        while(p != NULL){
            printf("%d %d ", p->coef, p->exp);
            p = p->next;
        }
        printf("\n");
    }
}

void destroy(int id){
    if(polyid[id] != NULL){
        term* p = polyid[id], *temp;
        while(p != NULL){
            temp = p;
            free(p);
            p = temp->next;
        }
    }
}

int main(){
    char c[100];
    while(1){
        if(!fgets(c, sizeof(c), stdin)) break;
        c[strcspn(c, "\n\r")] = '\0';
        if(strcmp(c, "*") == 0) break;
        if(strncmp(c, "Create ", 7) == 0){
            int id;
            sscanf(c+7, "%d", &id);
            create(id);
        }
        if(strncmp(c, "AddTerm ", 8) == 0){
            int id, coef, exp;
            sscanf(c+8, "%d %d %d", &id, &coef, &exp);
            polyid[id] = addterm(id, coef, exp);
        }
        if(strncmp(c, "EvaluatePoly ", 13) == 0){
            int id, val;
            sscanf(c+13, "%d %d", &id, &val);
            EvaluatePoly(id, val);
        }
        if(strncmp(c, "AddPoly ", 8) == 0){
            int id1, id2, resid;
            sscanf(c+8, "%d %d %d", &id1, &id2, &resid);
            AddPoly(id1, id2, resid);
        }
        if(strncmp(c, "PrintPoly ", 10) == 0){
            int id;
            sscanf(c+10, "%d", &id);
            printpoly(id);
        }
        if(strncmp(c, "Destroy ", 8) == 0){
            int id;
            sscanf(c+8, "%d", &id);
            destroy(id);
        }
    }
    //printlist();
}