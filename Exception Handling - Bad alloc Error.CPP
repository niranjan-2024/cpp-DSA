#include<iostream>
#include<exception>
using namespace std;
int main(){
   
   try{
      int* ptr=new int[100000000000000];
      delete[] ptr;
   }
   
   catch (bad_alloc e){
      cout<<"cannot allocate memory"<<endl;
      cout<<"error "<<e.what()<<endl;
   }
   return 0;
}
