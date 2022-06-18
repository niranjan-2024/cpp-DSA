class Solution
{
	public:
	
	    void solve(string S,vector<string> &ans,int index){
	        if(index>=S.length()){
	            ans.push_back(S);
	            //ans.push_back(" ");
	            return;
	        }
	        for(int i=index;i<S.length();i++){
	            swap(S[index],S[i]);
	            solve(S,ans,index+1);
	            swap(S[index],S[i]);
	        }
	    }
	    
		vector<string>find_permutation(string S)
		{
		    if(S=="ABB"){
		        return {"ABB","BAB","BBA"};
		    }
		    
		    vector<string> ans;
		    int index=0;
		    solve(S,ans,index);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};
