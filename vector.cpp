#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
int main(){
    vector<int>vec={1,2,3,4,5,5,6,8,7,45};
    cout<<vec[0]<<endl;
    cout<<"poping element"<<endl;
    vec.pop_back();
    cout<<"printing first element"<<"  "<<vec.front()<<endl;
    cout<<"printing last element"<<"  "<<vec.back()<<endl;
    for(int val: vec){//how to use loop in vector
        cout<<val<<endl;
    }
    
    vector<int>gec(3,0);
     gec.push_back(80);
     gec.push_back(85);
     gec.push_back(89);
     gec.push_back(95);
     cout<<gec.size()<<endl;
     for(int val: gec){
        cout<<val<<endl;
     }
    // vector<int>vec;
    // vec.push_back(85);
    // vec.push_back(89);
    // vec.push_back(88);
    // cout<<vec.capacity()<<endl;
    // cout<<vec.size()<<endl;
}
