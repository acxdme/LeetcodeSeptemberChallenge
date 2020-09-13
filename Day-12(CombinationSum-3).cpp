/*
Time complexity : O(9Ck)
Space complexity : O(size of result )
My approach : Recursively make the the permutations and push back if valid permutation exist.
*/

class Solution {


vector<vector<int>> result;
    void helperSum(int k, int n , vector<int>& combination, int start)
    {
        if(combination.size()== k and n ==0)
        {
            result.push_back(combination);
            return;
        }
        
        for(int i=start; i<=9;i++)
        {
            combination.push_back(i);
            helperSum(k,n-i,combination,i+1);
            combination.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        if(n==0)
            return result;
        vector<int> combination;
        helperSum(k,n,combination,1 );
        
        return result;
        
    }
};
