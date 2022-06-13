class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        if(str1.length()!=str2.length()){
            return false;
        }
        int a[26] = {0};
        int b[26] = {0};
        
        int index1;
        for(int i=0;i<str1.length();i++){
            index1 = str1[i] - 'a';
            a[index1]++;
        }
        
        int index2;
        for(int i=0;i<str2.length();i++){
            index2 = str2[i] - 'a';
            b[index2]++;
        }
        for(int i=0;i<str1.length();i++){
            index1 = str1[i] - 'a';
            index2 = str2[i] - 'a';
            if(a[index1]!=b[index2]){
                return false;
            }
        }
        return true;
    }
};
