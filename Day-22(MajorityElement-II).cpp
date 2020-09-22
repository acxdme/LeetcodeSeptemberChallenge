/*
Time complexity : O(N)
Space complexity : O(1)
My approach : At most the majority elements can be 2 , for the most optimal solution we use the moore vooting law algorithm.
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int nums1=-1;
        int nums2=-1;
        int c1=0,c2=0;
        vector<int> answer;
        int n= nums.size();
        if(nums.size()==0) return answer;
        for(int i=0;i<nums.size();i++)
        {
            if(nums1==nums[i]) c1++;
            else if( nums2 ==nums[i]) c2++;
            else if( c1==0) {nums1=nums[i]; c1=1;}
            else if( c2==0) {nums2=nums[i]; c2=1;}
            else
            {
                c1--;
                c2--;
            }
        }
        if(nums1==nums2) 
        {
            answer.push_back(nums1);
            return answer;
        }
         int count=0,count2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==nums1) count++;
            if(nums[i]==nums2) count2++;
            
        }
        if(count > n/3 ) answer.push_back(nums1);
        if(count2 > n/3) answer.push_back(nums2);
        
        
        return answer;
        
        
    }
};
