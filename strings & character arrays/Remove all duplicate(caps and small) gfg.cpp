class Solution{
public:
	string removeDuplicates(string S) {
	    string st="";
        int a[26]={0};
        int A[26]={0};
        for(int i=0;i<S.length();i++)
        {
            if(S[i]>='a' && S[i]<='z'){
                a[S[i]-'a']++;
            }
            else{
                A[S[i]-'A']++;
            }
        }
   
        for(int i=0;i<S.length();i++)
        {
            if(S[i]>='a' && S[i]<='z'){
                if(a[S[i]-'a']>=1)
                {
                    st.push_back(S[i]);
                    a[S[i]-'a']=0;
                }
            }
            else{
                if(A[S[i]-'A']>=1)
                {
                    st.push_back(S[i]);
                    A[S[i]-'A']=0;
                }
            }
           
        }
        return st;
	}
};
