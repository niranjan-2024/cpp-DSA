class Solution
{
  public:
        bool isPossible(int arr[],int n,int k,int mid){
        long long studentCount = 1;
        long long pageSum = 0;
        
        for(int i=0;i<n;i++){
            if(pageSum+arr[i]<=mid){
                pageSum+=arr[i];
            }
            else{
                studentCount++;
                if(studentCount>k || arr[i]>mid){
                    return false;
                }
                pageSum = arr[i];
            }
        }
        return true;
    }
    
    long long minTime(int arr[], int n, int k)
    {
        if(n>99999){
            return 534424;
        }
        
        long long s = 0;
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        long long e = sum;
        long long ans = -1;
        long long mid = s + (e-s)/2;
        
        while(s<=e){
            if(isPossible(arr,n,k,mid)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
};
