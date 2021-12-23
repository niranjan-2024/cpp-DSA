#include<iostream>
#include<list>
using namespace std;
int main(){
   list<string> names{"A","B","C"};
   for(string var : names){
      cout<<var<<" ";
   }
   cout<<endl;
names.push_front("M");
names.push_back("N");
for(string var : names){
      cout<<var<<" ";
   }
   cout<<endl;
cout<<names.front();
cout<<endl;
cout<<names.back();
cout<<endl;
names.pop_back();
names.pop_front();
for(string var : names){
      cout<<var<<" ";
   }
   cout<<endl;
   return 0;
}
