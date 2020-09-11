/*

Time complexity : O(N)

Space complexity : O(1)

My approach :  maintain current max , current min , previous max , previous min  and update the answer as max(currentmax, answer)
               current_max = max( a[i] , previous_max *a[i], previous_min* a[i])
               current_min = min ( a[i] , previous_min * a[i] ,previous_min * a[i])
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n =nums.size();
        int c_max = nums[0];
        int c_min = nums[0];
        int p_max =nums[0];
        int p_min = nums[0];
        int ans =nums[0];
        for(int i=1 ;i<n;i++)
        {
            c_max = max ( p_max *nums[i] , max(nums[i],p_min*nums[i]));
            c_min = min ( p_max *nums[i] , min(nums[i],p_min*nums[i]));
            ans = max (ans,c_max);
            p_max = c_max;
            p_min = c_min;
        }
        return ans;
    }
};

