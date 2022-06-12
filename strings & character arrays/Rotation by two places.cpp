class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
bool isRotated(string str1, string str2)
   {
       // Your code here
       int n = str1.length();
       
       // Create a start string with first two characters
       string start = ""; 
       start += str1[0];
       start += str1[1];
       
       // Create an end string with last two characters
       string end = ""; 
       end += str1[n-2];
       end += str1[n-1];
       
       // Create a middle string excluding first two and last two characters
       string middle = "";
       for(int i=2;i<n-2;i++){
           middle+=str1[i];
       }
       
       // Check for clockwise and anti-clockwise rotations
       if(middle+end+start == str2 || end+start+middle == str2)
           return true;
       else
           return false;
   }

};
