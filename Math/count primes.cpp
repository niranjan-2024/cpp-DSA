class Solution {
  public:
       int countPrimes(int L, int R) {
         vector<bool>isprime(R+10,1);
         isprime[1]=isprime[0]=false;
         for(int i=2;i*i<=R;i++){
             if(isprime[i]){
               for(int j=2*i;j<=R;j+=i){
                   isprime[j]=false;
               }
           }
       }
       int count=0;
       for(int i=L;i<=R;i++){
           if(isprime[i]){
               count++;
           }
       }
       return count;
    }
};
