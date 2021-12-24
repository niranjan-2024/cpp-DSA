#include<iostream>
using namespace std;

template <typename T>
T add(T num1,T num2){
   return(num1+num2);
}

int main(){
   int result1;
   double result2;
   result1 = add<int>(2,4);
   result2 = add<double>(2.345,5.432);
   cout<<result1<<endl;
   cout<<result2;
   return 0;
}
