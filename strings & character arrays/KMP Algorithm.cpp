class Solution
{
    public:
        
        void lps(string pat, vector<int> &ls)
        {
        int len =0, i=1;
        ls[0]=0;
        while(i<pat.length())
        {
            if(pat[i]==pat[len]) ls[i++] = ++len;
            else
                if(len ==0) ls[i++] = 0;
                else len=ls[len-1];
        }
        }
    
        vector <int> search(string pat, string txt)
        {
        int n = pat.length();
        int m = txt.length();
        vector<int> ls(n);
        lps(pat, ls);
        int j=0,i=0;
        vector<int> ans;
        while(i<m)
        {
            if(txt[i]==pat[j]) i++,j++;
            if(j==n)
            {
                ans.push_back(i-j+1);
                j = ls[j-1];
            }
            else if(i<m and txt[i]!=pat[j])
            {
                if(!j) i++;
                else j = ls[j-1];
            }
        }
        return ans;
        }
     
};
