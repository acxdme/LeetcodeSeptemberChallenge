/*
 Time complexity : O(N)
 Space complexity : O(1)
 My approach : create hashes for string s and string t and then compare hashes to find out the extra added element.
*/

class Solution {
public:
    char findTheDifference(string s, string t) {
        int hash1[26]={0};
        for(int i=0;i<s.size();i++)
        {
            hash1[s[i]-'a']++;
        }
        int hash2[26]={0};
        for(int i=0;i<t.size();i++)
        {
            hash2[t[i]-'a']++;
        }
        
        char ans;
        for(int j=0;j<26;j++)
        {
            if(hash1[j]!=hash2[j])
            {
                ans=(char)(j+97);
                break;
            }
        }
        
        return ans;
    }
};
