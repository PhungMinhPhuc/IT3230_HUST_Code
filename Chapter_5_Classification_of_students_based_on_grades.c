/*Given the profiles of n students, each profile has the following information:
studentID: string (length from 1 to 10) representing the student identifier (id)
totalGrade: int (grades of students are distinct)
Compute the position of each student based on the total grade (the number of students having smaller grades).

Input
Line 1: contains a positive integer n (1 <= n <= 100000)
Line i+1 (i = 1, 2, ..., n): contains a string <studentID> and a positive integer <grade> in which <grade> is the total grade of student <studentID>

Output
Each line is the student id and his position (sorted by student id)

Example
Input
5
S000003 3
S000002 6
S000005 5
S000004 10
S000001 8

Output 
S000001 3
S000002 2
S000003 0
S000004 4
S000005 1*/

/*Cách 1: O(n^2)*/
// #include <string.h>
// #include <stdio.h>
// #include <ctype.h>
// #include <stdlib.h>

// #define maxlen 1000000

// typedef struct inf{
//     char id[11];
//     int grade;
//     int position;
// } inf;

// int main(){
//     int n;
//     inf a[maxlen];
//     scanf("%d", &n);
//     for(int i=0; i<n; i++){
//         scanf("%s %d", a[i].id, &a[i].grade);
//     }
//     for(int i=0; i<n-1; i++){
//         for(int j=1+i; j<n; j++){
//             if(a[i].grade > a[j].grade){
//                 inf temp = a[i];
//                 a[i] = a[j];
//                 a[j] = temp;
//             }
//         }
//     }
//     for(int i=0; i<n; i++) a[i].position = i;
//     for(int i=0; i<n-1; i++){
//         for(int j=1+i; j<n; j++){
//             if(strcmp(a[i].id, a[j].id) > 0){
//                 inf temp = a[i];
//                 a[i] = a[j];
//                 a[j] = temp;
//             }
//         }
//     }
//     for(int i=0; i<n; i++) printf("%s %d\n", a[i].id, a[i].position);
// }

/*Cách 2: O(nlogn)*/
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 100000

typedef struct inf{
    char id[11];
    int grade;
    int position;
} inf;

int cmp1(void const * ptr1, void const* ptr2){
    inf *x = (inf*)ptr1;
    inf *y = (inf*)ptr2;
    return x->grade - y->grade;
}

int cmp2(void const * ptr1, void const* ptr2){
    inf *x = (inf*)ptr1;
    inf *y = (inf*)ptr2;
    return strcmp(x->id, y->id);
}

int main(){
    int n;
    inf a[maxlen];
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%s %d", a[i].id, &a[i].grade);
    qsort(a, n, sizeof(inf), cmp1);
    for(int i=0; i<n; i++) a[i].position = i;
    qsort(a, n, sizeof(inf), cmp2);
    for(int i=0; i<n; i++) printf("%s %d\n", a[i].id, a[i].position);
}