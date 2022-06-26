class Solution{
    public:

    //Function to check if two arrays are equal or not.
    bool check(vector<ll> A, vector<ll> B, int N) {
        unordered_map<ll,int> m1;
        unordered_map<ll,int> m2;
        for(int i=0;i<N;i++){
            m1[A[i]]++;
            m2[B[i]]++;
        }
        for(auto x:m1){
            if(x.second!=m2[x.first]) return false;
        }
        return true;
    }
};
