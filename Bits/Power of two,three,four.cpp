//Power of two
       return n > 0 && not (n & n - 1);


//Power of three
       //1
           // 3^19 =1162261467, 
	         // 3^20 is exceding  Integer_Range So 3^19 is the highest power in Integer Range  
           return ( n>0 &&  1162261467%n==0);
       //2
          return fmod(log10(n)/log10(3), 1)==0;

//Power of four
       //1
           return n>0 && (n&(n-1))==0 && (n&0x55555555);
		       // n>0, n should be positive
		       // n&(n-1) ensure it is power of 2
		       // 5 is "0101" so n&0x55555... ensure that set bit is at the even position.
		       // soo if n is power of 2 and set bit is at even position -> n is power of 4
       //2
           return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
