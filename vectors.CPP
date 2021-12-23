#include<iostream>
#include<vector>
using namespace std;
int main(){
   vector<int> marks1 = {12,23,34};
   vector<int> marks2  {12,23,34};
   vector<int> marks3(3,12);
   for(int i: marks1){
      cout<<i<<" ";
   }
   cout<<endl;
      for(int i: marks2){
      cout<<i<<" ";
   }
   cout<<endl;
      for(int i: marks3){
      cout<<i<<" ";
   }
   cout<<endl;
marks1.push_back(20);
   for(int i: marks1){
      cout<<i<<" ";
   }
   cout<<endl;
int number = marks1.at(3);
cout<<number;
cout<<endl;
marks1.at(2) = 50;
   for(int i: marks1){
      cout<<i<<" ";
   }
   cout<<endl;
   marks1.pop_back();
   for(int i: marks1){
      cout<<i<<" ";
   }
   
   return 0;
}
