/*
Time complexity : O(N)
Space complexity : O(1)
My approach : if the i+1th prices is smaller than the ith prices the minimum price is the min(minimumprice,va***lue at i+1 index)
              maximum prices is the ith price at each iteration of i and the final_prices is max (final_price, maxi-mini)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
     int n= prices.size();
     if(n==0)
         return 0;
     int final_answer=0;
     int mn=prices[0],mx= prices[0];
     for(int i=1;i<n;i++)
     {
         mx =prices[i];
         
         if(prices[i] <= prices[i-1])
             mn = min(prices[i],mn);
            
         final_answer = max ( final_answer, mx-mn);
         
     }
        
        return final_answer;
        
    }
};
