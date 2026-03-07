/*A matrix 9 x 9 is called a sudoku solution if it satisfies following constraints
Each element is an integer from 1 to 9
Elements on each row are distinct
Elements on each column are distinct
Elements on each sub-square 3x3 are distinct (the matrix is divided into 9 distinct subsquares of size 3x3) 

Write a program that checks whether or not a given matrix is a sudoku solution 
Input
Line 1: contains a positive integer T which is the number of matrix 9x9
Subsequent lines are blocks, each block contains a matrix 9x9 with the following format
Line i (i = 1, 2, ..., 9) contains the i line of the matrix

Output
Contains T lines, each line i (i = 1, 2, ..., T) contains 1 if the ith matrix is a sudoku solution, and contains 0, otherwise

Example
Input
2
1 2 3 4 5 6 7 8 9 
4 5 6 7 8 9 1 2 3 
7 8 9 1 2 3 4 5 6 
2 1 4 3 6 5 8 9 7 
3 6 5 8 9 7 2 1 4 
8 9 7 2 1 4 3 6 5 
5 3 1 6 7 8 9 4 2 
9 7 2 5 4 1 6 3 8 
6 4 8 9 3 2 5 7 1 
1 2 3 4 5 6 7 8 9 
4 5 6 7 8 9 1 2 3 
7 8 9 1 2 3 4 5 6 
2 1 4 3 6 5 8 9 7 
3 6 5 8 9 7 2 1 4 
8 9 7 2 1 4 3 6 5 
5 3 1 6 7 8 9 4 2 
9 7 8 5 4 2 6 3 1 
4 4 2 9 3 1 5 7 8 

Output
1
0*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define maxlen 10000

int n, a[9][9], count = 1;

int checkElement(int row, int col, int val){
    for(int i=0; i<9; i++) if(i != row && a[i][col] == val) return 0;
    for(int j=0; j<9; j++) if(j != col && a[row][j] == val) return 0;
    int xs = (row/3)*3;
    int ys = (col/3)*3;
    for(int i=xs; i<xs+3; i++){
        for(int j=ys; j<ys+3; j++){
            if(i != row && j != col && a[i][j] == val) return 0;
        }
    }
    return 1;
}

int checkSodoku(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(a[i][j] < 1 || a[i][j] > 9) return 0;
            if(checkElement(i, j, a[i][j]) == 0) return 0;
        }
    }
    return 1;
}

int main(){
    scanf("%d", &n);
    while(count <= n){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                scanf("%d", &a[i][j]);
            }
        }
        if(checkSodoku() == 1) printf("1\n");
        else printf("0\n");
        count ++;
    }
}