class Solution {
public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        sort(X.begin(),X.end(),greater<int>());
        sort(Y.begin(),Y.end(),greater<int>());
        
        int i=0;
        int j=0;
        
        int hzCount=1;
        int vzCount=1;
        
        int sum=0;
        
        while (i<M && j<N){
            if(X[i] > Y[j]){
                sum+=X[i]*vzCount;
                i++;
                hzCount++;
            }
            else{
                sum+=Y[j]*hzCount;
                j++;
                vzCount++;
            }
        }
        
        while(i<M){
            sum+=X[i]*vzCount;
            i++;
        }
        
        while(j<N){
            sum+=Y[j]*hzCount;
            j++;
        }
        
        return sum;
    }
};
