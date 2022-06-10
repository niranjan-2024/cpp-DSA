class Solution{
public:	
	
	
	int isPalindrome(string S)
	{
	    int s = 0;
	    int e = S.length() - 1;
	    
	    while(s<e){
	        if(S[s]!=S[e]){
	            return 0;
	            break;
	        }
	        else{
	            s++;
	            e--;
	        }
	    }
	    return 1;
	}

};
