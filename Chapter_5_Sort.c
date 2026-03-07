/*Cài đặt thuật toán sắp xếp chọn (Selection Sort), sắp xếp chèn (Insertion Sort), sắp xếp nổi bọt (Bubble Sort), sắp xếp trộn (Merge Sort), sắp xếp nhanh (Quick Sort), sắp xếp vun đống (Heap Sort)*/
//Lưu ý: Các hàm trong đây viết thì phần tử đầu tiên có index = 1, không phải 0

#include <stdio.h>

#define maxlen 1000

//Selection Sort
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int a[], int n){
    for(int k=1; k<=n; k++){
        int min_index = k;
        for(int j=k+1; j<=n; j++){
            if(a[min_index] > a[j]) min_index = j;
        }
        swap(&a[min_index], &a[k]); // hoán đổi
    }
}

//Insertion Sort
void InsertionSort(int a[], int n){
    for(int i=2; i<=n; i++){
        int j = i;
        int last = a[i];
        while(j > 1 && a[j-1] > last){
            a[j] = a[j-1];
            j = j - 1;
        }
        a[j] = last;
    }
}

//Bubble Sort
void BubbleSort(int a[], int n){
    for(int i=1; i<=n-1; i++){
        for(int j=i+1; j<=n; j++){
            if(a[i] > a[j]) swap(&a[i], &a[j]);
        }
    }
}

//Merge Sort
void Merge(int a[], int first, int mid, int last){
    int tempa[maxlen], index = first;
    int first1 = first, last1 = mid;
    int first2 = mid + 1, last2 = last;
    while((first1 <= last1) && (first2 <= last2)){
        if(a[first1] < a[first2]){
            tempa[index] = a[first1];
            index++;
            first1++;
        }
        else{
            tempa[index] = a[first2];
            index++;
            first2++;
        }
    }
    while(first1 <= last1){
        tempa[index] = a[first1];
        index++;
        first1++;
    }
    while(first2 <= last2){
        tempa[index] = a[first2];
        index++;
        first2++;
    }
    for(int i=first; i<=last; i++) a[i] = tempa[i];
}

void MergeSort(int a[], int first, int last){
    if(first < last){
        int mid = (first + last)/2;
        MergeSort(a, first, mid);
        MergeSort(a, mid+1, last);
        Merge(a, first, mid, last);
    }
}

//Quick Sort
//Lưu ý copy cả hàm swap ở trên
int partition(int a[], int left, int right){//Phần tử chốt là phần tử đứng đầu
    int pivot = a[left], i = left, j = right + 1;
    while(i<j){
        i++;
        while(i <= right && a[i] < pivot) i++;
        j--;
        while(j >= left && a[j] > pivot) j--;
        swap(&a[i], &a[j]);
    }
    swap(&a[i], &a[j]);
    swap(&a[j], &a[left]);
    return j;
}

void QuickSort(int a[], int left, int right){
    int pivot;
    if(left < right){
        pivot = partition(a, left, right);
        if(left < pivot) QuickSort(a, left, pivot - 1);
        if(right > pivot) QuickSort(a, pivot + 1, right);
    }
}

//Heap Sort
void heapfy(){
    
}

void HeapSort(int a[], int n){
    
}

int main(){
    int x[15] = {-1,  5,  4,  6,  1,  2,  9,  7,  3,  8};
    MergeSort(x, 0, 9);
    for(int i=0; i<=9; i++) printf("%d ", x[i]);
    return 0;
}