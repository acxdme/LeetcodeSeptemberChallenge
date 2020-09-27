/*
Time complexity : O(N)
Space complexity : O(N)
My approach : convert it into merge interval problem.
*/
// this can also be done without using extra space for creating intervals.
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) 
    {
        int n= timeSeries.size();
        if(n==0) return 0;
         vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({timeSeries[i],timeSeries[i]+duration-1});
        }
        vector<pair<int,int>> m;
        pair<int,int> temp={v[0].first,v[0].second};
        for(int i=1;i<v.size();i++)
        {
            if(v[i].first <= temp.second ) 
            {
                temp.second = v[i].second;
            }
            else
            {
                m.push_back(temp);
                temp.first = v[i].first;
                temp.second =v[i].second;
            }
        }
                    m.push_back(temp);

         int answer=0;
        for(int i=0;i<m.size();i++)
        {
            answer += (m[i].second -m[i].first +1);
        }
        
        return answer;
        
    }
};
