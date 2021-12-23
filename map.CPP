#include<iostream>
#include<map>
using namespace std;
int main(){
   map<int,string> student = {{101,"A"},{102,"B"},{103,"C"}};
   student[104]="D";
   for(auto var : student){
      cout<<var.first<<" "<<var.second<<endl;
   }
   cout<<endl;
   cout<<endl;
   student.erase(102);
   for(auto var : student){
      cout<<var.first<<" "<<var.second<<endl;
   }
   return 0;
}
