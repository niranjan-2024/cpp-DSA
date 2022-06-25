class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& arr,int a, int b)
    {
        int n = arr.size();
        int i,j;
        j=0;
        for(i=0;i<n;i++){
            if(arr[i]<a){
                swap(arr[j++],arr[i]);
            }
        }
        j=n-1;
        for(i=n-1;i>=0;i--){
            if(arr[i]>b){
                swap(arr[j--],arr[i]);
            }
        }
    }
};
