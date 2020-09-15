/*
Time complexity  :  O(N)
Space complexity :  O(1)
My approach :  create current and prev string variables update prev when ' ' is encountered and current.size()> 0
               finally return prev.size() if current's size is zero otherwise return current.size();
*/

class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int n = s.size();
        if(n==0)
            return 0;
        
        string  prev;
        string current;
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                if(current.size()>0)
                prev= current;
                current.clear();
            }
            else
                 current+= s[i];       
        }
        
        if(current.size()==0 and prev.size()==0)
            return 0;
        if(current.size()==0 and prev.size()>0)
            return prev.size();
        
        return current.size();
    }
};
