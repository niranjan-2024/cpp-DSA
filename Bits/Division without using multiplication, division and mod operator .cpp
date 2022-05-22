class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
       if(divisor == 0) return (-1);
       if(dividend == 0) return (0);
       
       int sign;
       if((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) sign = 1;
       else sign = -1;
       
       dividend = abs(dividend);
       divisor = abs(divisor);
       
       long long quotient = 0;
       while(dividend >= divisor){
           long long x = 0;
           while((divisor<<x) <= dividend) x++;
           x--;
           
           quotient += 1<<x;
           dividend -= divisor<<x;
       }
       
       return (quotient*sign);
    }
};
