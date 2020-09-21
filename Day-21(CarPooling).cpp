/*
Time complexity : O(N^2)
Space complexity : O(N)
My approach : create a hash of the values of the passengers at the current instance of distance 
              if at any point the hash values exceed the capacity of the cab then return false.
              take care of the times when the end point of one trip is same as the starting point of other.
*/

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int hash[1002]={0};
        int n= trips.size();
        for(int i=0;i<n;i++)
        {
            for(int j=trips[i][1];j<trips[i][2];j++)
            {
                hash[j]+=trips[i][0];
                
            }
        }
        for(int i=0;i<1002;i++)
        {
            if(hash[i]>capacity )
            {
                return false;
            }
        }
        
        
        return true;
        
    }
};
