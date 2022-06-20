class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        vector<int> v(100000,0);
        for(int i=0;i<n;i++){
            v[arr[i]]++;
        }
        int count = 0;
        for(int i=0;i<v.size();i++){
            if(v[i]>(n/k)){
                count++;
            }
        }
        return count;
    }
};
