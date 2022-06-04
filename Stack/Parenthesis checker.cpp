class Solution
{
    public:
    //Function to check if brackets are balanced or not.
     bool ispar(string x)
   {
       // Your code here
       stack<int> s;
       
       for(int i=0;i<x.length();i++){
           
           if(x[i]=='(' || x[i]=='{' || x[i]=='['){
               s.push(x[i]);
           }else{
               if(s.empty()==true){
                   return false;
               }else if (ismatching(s.top(),x[i])==false){
                   return false;
               }
               else{
                   s.pop();
               }
           }
       }
       return (s.empty()==true);
   }
   bool ismatching(char a,char b){
       return (a=='(' && b==')') || (a=='[' && b==']') || (a=='{' && b=='}');
   }

};
