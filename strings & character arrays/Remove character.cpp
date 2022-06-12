class Solution {
  public:
    string removeChars(string s1, string s2) 
    {   
        for(int j=0;s2[j];j++)
        {
           for(int i=0;s1[i];i++)
           {
             if(s1[i]==s2[j])
             {
                s1.erase(i,1);
                i--;
             }
           }
        }
        return s1;
    }
};
