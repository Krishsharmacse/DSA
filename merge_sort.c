#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
void mergesort(int arr[],int p,int q, int r){
    int l;
    int m;
    int k;
    int i;
    int j;
    int *b;
    int *c;
    l=q-p+1;
    m=r-q;
    b=(int*)malloc((l+1)*sizeof(int));
    c=(int*)malloc((m+1)*sizeof(int));
    for (int i = 0; i < l; i++)
    {
        b[i]=arr[p+i];
    }
    for(int j=0;j<m;j++){
        c[j]=arr[q+1+j];
    }
    b[l]=INT_MAX;
    c[m]=INT_MAX;
    j=0;
    i=0;
    k=p;
    while (k<=r)
    {
        if(b[i]<=c[j]){
            arr[k]=b[i];
            i++;
        }
        else{
            arr[k]=c[j];
            j++;
        }
        k=k+1;
    }
    free(b);
    free(c);
}
void mergeSortRecursive(int arr[], int p, int r) {
    if (p < r) {
        int q = p + (r - p) / 2;
        mergeSortRecursive(arr, p, q);
        mergeSortRecursive(arr, q + 1, r);
        mergesort(arr, p, q, r);
    }
}
void printarray(int n, int arr[]){
    for(int i = 0;i<n;i++){
        printf("%d" "  ",arr[i]);
        
    }
}

int main(){
    int arr[]={3,6,5,87,32,64,45,98,99,75,62,32,45,1,5,15};
    int p=0;
    int q=8;
    int r = 16;
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Orignal Array Is shown below\n");
     printarray(n,arr);
     printf("Merged array is\n");
    mergeSortRecursive(arr,0,n-1);
    printarray(n,arr);
}
