class Solution
{
  public:
    
    void search(int arr[], int low, int high,int& ans)
    {
    if (low > high)
        return;
    if (low == high) {
        ans = arr[low];
        return;
    }
    int mid = (low + high) / 2;
 
    if (mid % 2 == 0) {
        if (arr[mid] == arr[mid + 1])
            search(arr, mid + 2, high,ans);
        else
            search(arr, low, mid,ans);
    }
 
    else {
        if (arr[mid] == arr[mid - 1])
            search(arr, mid + 1, high,ans);
        else
            search(arr, low, mid - 1,ans);
    }
}
    
    int findOnce(int arr[], int n)
    {
        int ans = 0;
        search(arr,0,n,ans);
        return ans;
    }
};
