/*Cách 1: Phương pháp Gauss, nghiệm chuẩn, tốc độ O(n^3)*/
// #include <stdio.h>

// int main(){
//     int n;
//     scanf("%d", &n);
//     double a[n][n+1], b[n], p, x[n];
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             scanf("%lf", &a[i][j]);
//         }
//     }
//     for(int i=0; i<n; i++){
//         scanf("%lf", &b[i]);
//         a[i][n] = b[i];
//     }
//     for(int k=0; k<n-1; k++){
//         for(int i=k+1; i<n; i++){
//             if(a[k][k] != 0){
//                 p = a[i][k]/a[k][k];
//                 for(int j=k; j<n+1; j++){
//                     a[i][j] = a[i][j] - p*a[k][j];
//                 }
//             }
//         }
//     }
//     for(int i=n-1; i>=0; i--){
//         double s = a[i][n];
//         for(int j=i+1; j<n; j++) s = s - x[j]*a[i][j];
//         x[i] = s/a[i][i];
//     }
//     printf("%d\n", n);
//     for(int i=0; i<n; i++) printf("%.4lf\n", x[i]);
//     return 0;
// }

/*Cách 1.5: Phương pháp Gauss, nghiệm chuẩn, tốc độ O(n^3) cải tiến dùng quy hoạch động*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    double **a = (double**)malloc(n*sizeof(double*));
    for(int i=0; i<n; i++) {
        a[i] = (double*)malloc((n+1)*sizeof(double));
    }
    double *x = (double*)malloc(n*sizeof(double));
    double p;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%lf", &a[i][j]);
        }
    }
    for(int i=0; i<n; i++){
        scanf("%lf", &a[i][n]);
    }
    for(int k=0; k<n-1; k++){
        for(int i=k+1; i<n; i++){
            if(a[k][k] != 0){
                p = a[i][k]/a[k][k];
                for(int j=k; j<n+1; j++){
                    a[i][j] = a[i][j] - p*a[k][j];
                }
            }
        }
    }
    for(int i=n-1; i>=0; i--){
        double s = a[i][n];
        for(int j=i+1; j<n; j++) s = s - x[j]*a[i][j];
        x[i] = s/a[i][i];
    }
    printf("%d\n", n);
    for(int i=0; i<n; i++) printf("%.4lf\n", x[i]);
    free(x);
    for(int i=0; i<n; i++) free(a[i]);
    free(a);
    return 0;
}

// /*Cách 2: Phương pháp lặp giải gần đúng*/
// #include <stdio.h>

// int main(){

// }