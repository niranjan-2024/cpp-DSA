class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        for(int i=0;i<=60;i++){
            long long int ans = pow(2,i);
            if(ans == n){
                return true;
            }
        }
        return false;
    }
};
