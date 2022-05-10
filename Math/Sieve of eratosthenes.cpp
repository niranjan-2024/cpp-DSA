class Solution
{
public:
   vector<int> sieveOfEratosthenes(int N)
   {
       vector<int>primes;
       bool arr[N+1]={false};
       arr[0]=arr[1]=true;

   for(int i=2;i*i<=N;i++){
       if(arr[i]==false){
           for(int j=i*i;j<=N;j+=i)
           arr[j]=true;
       }
   }

   for(int i=2;i<=N;i++){
       if(!arr[i])
       primes.push_back(i);
   }
   return primes;
   }
   

};
