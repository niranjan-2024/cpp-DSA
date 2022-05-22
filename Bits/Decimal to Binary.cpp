#include<math.h>
void toBinary(int N)
{
    int ans = 0;
    int i = 0;
    while(N!=0){
        int bit = N&1;
        ans = (bit*pow(10,i)) + ans;
        N = N>>1;
        i++;
    }
    
    printf("%d",ans);
}
