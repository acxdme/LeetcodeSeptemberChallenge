/*
Time complexity : O(N^2)
Space complexity : O(N) 
My approach :   take a valid substring of the given string (done in linear time)
                For each valid substring append it x number of times ( x = (givenString's size)/(SubstringsSize) -1 )
                Check is the made string is given to the original string.
*/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n= s.size();
        if(n==0)
            return false;
        for(int i=0; i<n-1;i++)
        {
            if( n % (i+1) != 0)
                continue;
            else
            {
            string temp = s.substr(0,i+1);
            for(int j=1; j< n/(i+1); j++)
            {
                temp += s.substr(0,i+1);
            }
                // cout<<temp<<endl;
            if(temp == s)
                return true;
            }
            
        }
        return false;
    }
};
