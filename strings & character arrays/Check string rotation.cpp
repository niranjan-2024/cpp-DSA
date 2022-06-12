class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        if(s1.length()!=s2.length()){
            return false;
        }
        string temp = s1+s1;
        if(temp.find(s2)!=-1){
            return true;
        }
        return false;
    }
};
