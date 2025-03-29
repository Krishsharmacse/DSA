#include<iostream>
using namespace std;

void bubblesort(int n,int arr[]){//O(n^2)
bool isswap = false;
    for(int i=0;i<=n-2;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                isswap=true;
            }
        }
        if(!isswap){
            return;
        }
    }
}
void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
int n=100;
int arr[]={37, 82, 15, 63, 4, 91, 28, 50, 73, 9, 46, 19, 85, 31, 67, 2, 94, 56, 39, 77, 12, 60, 33, 88, 5, 42, 79, 24, 96, 51, 7, 70, 22, 84
, 48, 13, 98, 35, 61, 17, 89, 44, 1, 76, 29, 53, 8, 95, 40, 68, 11, 83, 26, 58, 3, 92, 47, 72, 20, 86, 38, 64, 6, 99, 32, 75, 16, 54, 81, 25,
 93, 43, 69, 10, 87, 36, 62, 18, 97, 49, 74, 21, 90, 41, 65, 14, 100, 30, 57, 80, 23, 52, 78, 27, 95, 45, 71, 34, 59, 55, 66};
bubblesort(n,arr);
printarray(arr,n);
for(int k=0;k<=100;k++){
    cout<<k;
}
return 0;
}