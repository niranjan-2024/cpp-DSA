class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        unordered_map<int,int> map;
        int count = 0;
        for(int i=0;i<n;i++){
            int diff = k-arr[i];
            if(map.find(diff)!=map.end()){
                count+=map[diff];
            }
            map[arr[i]]++;
        }
        return count;
    }
};
