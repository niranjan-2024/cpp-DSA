class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    int res = 1;
		    while(n>0){
		        if(n&1){
		            res = ( 1LL * (res) * (x)%M)%M;
		        }
		        x = (1LL * (x)%M * (x)%M )%M;
		        n = n>>1;
		    }
		    return res;
		}
};
