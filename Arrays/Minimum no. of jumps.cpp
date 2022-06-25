class Solution{
  public:
    int minJumps(int arr[], int n){
        if(n<=1) return 0;
        if(arr[0]==0) return -1;
        
        int jumps = 0;
        int currentJumpEnd = 0;
        int farthest = 0;
        
        for(int i=0;i<n;i++){
            if(i==n-1) return (currentJumpEnd>=n-1)?jumps:-1;
            farthest = max(farthest,i+arr[i]);
            if(i==currentJumpEnd){
                jumps++;
                currentJumpEnd = farthest;
            }
        }
        return -1;
    }
};
