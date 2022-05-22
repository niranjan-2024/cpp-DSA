class Solution {
  public:
    int findPosition(int N) {
       if(N<=0) return -1;
       int pos=1;
       int cnt=0;
       while(N>0){
           if((N&1)!=1){
               pos++;
           }
           else cnt++;
           N=N>>1;
       }
       
      if(cnt>1) return -1;
      return pos;
    }
};
