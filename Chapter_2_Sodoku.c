#include <stdio.h>

int a[9][9];
int count = 0;

// void print(){
//     printf("\n--------%d--------\n", count);
//     for(int i = 0; i < 9; i++){
//         for(int j = 0; j < 9; j++){
//             printf("%d ", a[i][j]);
//         }
//         printf("\n");
//     }
// }

int check(int x, int y, int v){
    for(int i = 0; i < 9; i++) if(a[i][y] == v) return 0;
    for(int j = 0; j < 9; j++) if(a[x][j] == v) return 0;
    int xs = (x/3)*3;
    int ys = (y/3)*3;
    for(int i = xs; i < xs+3; i++){
        for(int j = ys; j < ys+3; j++){
            if(a[i][j] == v) return 0;
        }
    }
    return 1;
}

void try(int row, int col){
    if(col == 9){
        if(row == 8){
            count++;
            // print();
            return;
        }
        else{
            row++;
            col = 0;
        }
    }
    if(a[row][col] != 0) try(row, col+1);
    else{
        for(int v = 1; v <= 9; v++){
            if(check(row, col, v)){
                a[row][col] = v;
                try(row, col+1);
                a[row][col] = 0;
            }
        }
    }
}

int main(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            scanf("%d", &a[i][j]);
        }
    }
    try(0,0);
    printf("%d", count);
}