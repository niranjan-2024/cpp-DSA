class Solution{
public:	
		
	string removeDups(string S) 
	{
	    string st="";
        int a[26]={0};
        for(int i=0;i<S.length();i++)
        {
           a[S[i]-'a']++;
        }
   
        for(int i=0;i<S.length();i++)
        {
           if(a[S[i]-'a']>=1)
             {
                st.push_back(S[i]);
                a[S[i]-'a']=0;
             }
        }
        return st;
	}
};
