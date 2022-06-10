class Solution
{
  public:
    string reverseWords (string s)
    {
       int low=0;
       int n=s.length();
       
       for(int i=0;i<n;i++){
           if(s[i]=='.' ){
               reverse(s.begin()+low,s.begin()+i);
               low=i+1;
           }
       }
       
       reverse(s.begin()+low,s.begin()+n);
       return s;
    }
};
