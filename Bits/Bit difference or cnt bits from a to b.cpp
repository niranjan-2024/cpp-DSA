class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        int n=a^b;
        int cnt = 0;
        while(n>0){
            n=n&(n-1);
            cnt++;
        }
        return cnt;
    }
};
