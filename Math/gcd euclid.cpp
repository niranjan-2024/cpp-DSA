class Solution {
  public:
  long long gcd(int a,int b){
      return b==0?a:gcd(b,a%b);
  }
    vector<long long> lcmAndGcd(long long A , long long B) {
        vector<long long>arr;
        long long hcf = gcd(A,B);
        
        
        long long lcm = (A*B)/hcf;
        
        arr.push_back(lcm);
        arr.push_back(hcf);
        return arr;
    }
};
