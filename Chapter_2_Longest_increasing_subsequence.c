/*Longest Increasing subsequence
Given a sequence a of positive a1, a2, . . ., an. A subsequence of a is defined to be the sequence obtained by removing some elements. Find the subsequence of a such that the elements is in an increasing order and the number of elements of the subsequence is maximal.

Input
Line 1: contains a positive integer n (1 <= n <= 10000)
Line 2: contains n elements of the given sequence (1 <= ai <= 10000)
Output
The length of the subsequence found.

Example
Input 
6
5 8 2 8 10 10 

Output
3
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 100000

int main(){
    int n, a[maxlen], f[maxlen], max = -1e9;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        f[i] = 1;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(a[j] < a[i] && f[i] < f[j] + 1) f[i] = f[j] + 1;
        }
    }
    for(int i=0; i<n; i++){
        if(max <= f[i]) max = f[i];
    }
    printf("%d", max);
}