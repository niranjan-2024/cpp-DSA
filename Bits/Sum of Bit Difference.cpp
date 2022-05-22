class Solution{
public:
    int countBits(int N, long long int arr[])
    {
        long long int ans = 0; 
        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (long long int j = 0; j < N; j++)
                if ((arr[j] & (1 << i)))
                    count++;
        ans += (count * (long)(N - count) * 2);
    }
    ans = ans%1000000007L;
    return (int)ans;
    }
};
