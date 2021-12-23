#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
   vector<int> num {4,0,2,3,1};
   vector<int>::iterator min;
   vector<int>::iterator max;
   for(int i : num){
      cout<<i<<", ";
   }
   cout<<endl;
   sort(num.begin(),num.end());
   for(int i : num){
      cout<<i<<", ";
   }
   min = min_element(num.begin(),num.end());
   max = max_element(num.begin(),num.end());
   cout<<endl;
   cout<<*min<<"---"<<*max;
   cout<<endl;
   reverse(num.begin(),num.end());
    for(int i : num){
      cout<<i<<", ";
   }
   
   return 0;
}
