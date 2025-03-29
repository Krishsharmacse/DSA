#include <iostream>
using namespace std;
int main(){
int n;
cout<<"entre the size you want in your pattern"<<endl;;
cin>>n;
for(int i=0;i<=n-1;i++){
   for(int j=0;j<=n-1;j++){
      cout<<"*";
   
   }
   cout<<endl;
}
for(int i=0;i<=n-1;i++){
   for(int j=0;j<=n;j++){
      cout<<j;
   }
   cout<<endl;
}


for(int i=0;i<=n-1;i++){
   char ch='A';
   for(int j=0;j<=n-1;j++){
      cout<<ch;
      ch=ch+1;
   }
   cout<<endl;
}

int num=1;
for(int i=0;i<=n-1;i++){
   for(int j=0;j<=n-1;j++){
      cout<<num<<" ";
      num++;
   }
   cout<<endl;
}
char ch = 'A';
for(int i=0;i<=n-1;i++){
   for(int j=0;j<=n-1;j++){
      cout<<ch;
      ch=ch+2;
   }
   cout<<endl;
}
for(int i=0;i<=n-1;i++){
   for(int j=0;j<=i;j++){
      cout<<j;
}
cout<<endl;
}
for(int i=0;i<=n;i++){
   ch='A';
   for(int j=0;j<=i;j++){
      cout<<ch;
      ch++;
   }
   cout<<endl;
}
for(int i=0;i<=n;i++){
   for(int j=0;j<=i;j++){
      cout<<"*";
   }
   cout<<endl;
}

for(int i=0;i<=n-1;i++){
   for(int j=0;j<=i;j++){
      cout<<ch;
      ch=ch+1;
   }
   cout<<endl;
}
for(int i=0;i<n;i++){
   for(int j=i+1;j>0;j--)
   {
      cout<<j;
   }
   cout<<endl;
}

for(int i=0;i<n-1;i++){
   for(int j = i+1;j>0;j--){
   cout<<num;
   num++;
   }
   cout<<endl;
}
 return 0;
}