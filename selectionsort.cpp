#include<iostream>
using namespace std;
void selectionsort(int arr[],int n){
    for (int i = 0; i < n; i++)
    {for (int j = i; j > 0; j--)
    {
       if(arr[j]<arr[j-1]){
        swap(arr[j],arr[j-1]);
       }
    }
    
      
    }
}
    
void printarray(int n,int arr[]){
for(int j=0; j<n;j++){
cout<<arr[j];
}
cout<<endl;
}
int main(){
    int n=10;
   int arr[]={9,8,7,6,4,5,3,1,2,0};
    selectionsort(arr,n);
    printarray(n,arr);
}