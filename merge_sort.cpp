#include<iostream>
using namespace std;

void merge(long arr[], long i, long mid, long j){
    long mergedArray[j-i+1];
    long Index=0;
    long x = i, y = mid+1;

    while(x <=mid && y <= j){
        if(arr[x] <= arr[y]){
            mergedArray[Index] = arr[x];
            x++;
        } else{
            mergedArray[Index] = arr[y];
            y++; 
        }
        Index++;
    }

    while(x<=mid){
        mergedArray[Index] = arr[x];
        Index++;
        x++;
    }

    while(y<=j){
        mergedArray[Index] = arr[y];
        Index++;
        y++; 
    }

     for (long k = 0; k < Index; k++) {
        arr[i + k] = mergedArray[k];
    }
 
}


void mergeSort(long arr[], long i, long j){
   
    if(i>=j){
        return;
    }

    long mid = i + (j-i)/2;
    
    printf("%d\n", mid);

    mergeSort(arr, i, mid);
    mergeSort(arr, mid+1, j);

    merge(arr, i, mid, j);
}


int main(){
    long a[] = {12,15,16,22,21};

    int n = sizeof(a) / sizeof(a[0]) ;
    mergeSort(a, 0, n);

    for(long i = 0; i<6; i++){
        printf("%d", a[i]);
    }
}