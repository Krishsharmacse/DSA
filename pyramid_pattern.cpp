#include<iostream>
using namespace std;
int main (){
    int n;
    cout<<"entre the size you want ";
    cin>>n;
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=n-i-1;j++){
            cout<<" ";
        }
        for(int j=0;j<=i+1;j++){
            cout<<j;
        }
        for(int j=i;j>0;j--){
            cout<<j;
        }
        cout<<endl;
    }

    for(int i=0;i<=n-1;i++){
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        cout<<"*";
        if(i!=0){
            for(int j=0;j<2*i-1;j++){
                cout<<" ";
            }
            cout<<"*";
        }
      cout<<endl;
    }
    return 0;
}