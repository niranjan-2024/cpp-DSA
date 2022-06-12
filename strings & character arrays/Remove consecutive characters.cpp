class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        int i=0;
        int n = S.size();
        string sn;
        while(i<=n){
            if(S[i]!=S[i+1]){
                sn = sn + S[i];
            }
            if(i==n){
                sn = sn+S[i];
            }
            i++;
        }
        return sn;
    }
};
