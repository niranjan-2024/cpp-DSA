class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        vector<double> v;
        for(int i=0;i<array1.size();i++){
            v.push_back(array1[i]);
        }
        for(int i=0;i<array2.size();i++){
            v.push_back(array2[i]);
        }
        sort(v.begin(),v.end());
        int n = v.size();
        int x = n/2;
        if(n%2==0){
            return (double)((v[x-1]+v[x])/2);
        }
        else{
            return (double)v[x];
        }
    }
};
