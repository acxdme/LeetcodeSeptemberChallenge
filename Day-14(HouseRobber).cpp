/*
Time complexity : O(N)
Space complexity : O(N) but can we done in O(1) space
My approach : This is a dynamic programming problem 
               The max value at each valid i is the max of current value at i+ value at i-2th postition or value at i-1 th position.
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==0 )
            return 0;
        
        int dp[n];
        dp[0]=nums[0];
        for(int i=1 ;i<n;i++)
        {
            if(i-2 >= 0)
            {
                dp[i]= max(nums[i]+dp[i-2], dp[i-1]);
            }
            else
            {
                dp[i] = max(nums[i-1],nums[i]);
            }
                
        }
        return dp[n-1];
        
    }
};

// O(1) space
class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if(n==0) 
            return 0;
        int value1=nums[0];
        if(n==1) 
        {
            return value1;
        }
        int value2= max(nums[0],nums[1]);
        if(n==2 )
        {   //    1 2 3 1
            return value2;
        }
        int currentMax=0;
        for(int i=2;i<n;i++)
        {
            currentMax = max (nums[i]+value1,value2);
            value1 = value2;
            value2 = currentMax;
        }
        
        return currentMax;
        
    }
};
