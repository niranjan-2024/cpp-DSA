class Solution{
public:
    bool isPrime(int n){
       if(n<=1){
           return false;
       }
       if(n==2 || n==3){
           return true;
       }
       if(n%2==0 || n%3==0){
           return false;
       }
       for(int i=5;i*i<=n;i=i+6){
           if(n%i==0 || n%(i+2)==0){
               return false;
           }
       }
       return true;
   }
   
    long long primeProduct(long long L, long long R){
        long long res=1;
        long long m = pow(10,9)+7;
        for(int i=L;i<=R;i++){
           if(isPrime(i)){
               res=res*i;
               
           }
           res=res%m;
       }
       return res%m;
    }
};
