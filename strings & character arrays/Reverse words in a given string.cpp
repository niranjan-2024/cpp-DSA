class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
       vector<string> words;
       string temp="";
       
       for(int i=0; i<S.length(); i++){
           if(S[i]=='.'){
               words.push_back(temp);
               temp="";
           }
           else{
               temp+=S[i];
           }
       }
       
       words.push_back(temp);
       
       string rev="";
       
       for(int i=words.size()-1; i>0; i--){
           rev+=words[i]+".";
       }
       
       rev+=words[0];
       return rev;
       
    } 
};
