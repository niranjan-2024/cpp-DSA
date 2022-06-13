class Solution{
    
    public:
    int transfigure (string A, string B)
    {
    	int check[256]={0};
    	
    	if(A.length()!=B.length())
        {
            return -1;
        }
        
        for(int i=0;i<A.length();i++)
        {
            check[A[i]]++;
            check[B[i]]--;
        }
        
        for(int i=0;i<256;i++)
        {
            if(check[i]!=0)
            return -1;
        }
        
        int len1=A.length();
        int len2=B.length();
        int res=0;
        
        while(len1>=0)
        {
            if(A[len1]!=B[len2])
            {
                res++;
            }
            else
            {
                len2--;
            }
            len1--;
        }
        
        return res;
    }
};
