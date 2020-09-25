/*
Time complexity : O(Nlogn)
space complexity : O(N)

Facts: 
        First, we convert each integer to a string. Then, we sort the array of strings.
While it might be tempting to simply sort the numbers in descending order, this causes problems for sets of numbers with the same leading digit. 
For example, sorting the problem example in descending order would produce the number 95343039534303, while the correct answer can be achieved by transposing the 33 and the 3030.
Therefore, for each pairwise comparison during the sort, we compare the numbers achieved by concatenating the pair in both orders.
We can prove that this sorts into the proper order as follows:

Assume that (without loss of generality), for some pair of integers aa and bb, our comparator dictates that aa should precede bb in sorted order.
This means that a\frown b > b\frown aa⌢b>b⌢a (where \frown⌢ represents concatenation).
For the sort to produce an incorrect ordering, there must be some cc for which bb precedes cc and cc precedes aa.
This is a contradiction because a\frown b > b\frown aa⌢b>b⌢a and b\frown c > c\frown bb⌢c>c⌢b implies a\frown c > c\frown aa⌢c>c⌢a.
In other words, our custom comparator preserves transitivity, so the sort is correct.

Once the array is sorted, the most "signficant" number will be at the front.
There is a minor edge case that comes up when the array consists of only zeroes, so if the most significant number is 00, we can simply return 00.
Otherwise, we build a string out of the sorted array and return it.
*/

class Solution {
public:
   static bool comp (string& a, string&b)
    {
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums) {
        int n =nums.size();
        vector<string> v;
        for(auto i: nums)
            v.push_back(to_string(i));
        sort(v.begin(),v.end(),comp);
        
        string res;
        for(auto i : v)
        {
            res+=i;
        }
        while(res[0]== '0' and res.size()>1)
            res.erase(0,1);
        return res;
    }
};
