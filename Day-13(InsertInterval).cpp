/*
Time complexity :
Space complexity :
My approach :
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        vector<vector<int>> answer;
        int n= intervals.size();
        if(n==0)
        {
            answer.push_back(newInterval);
            return answer;
        }
        int flag=0;
        
        for(int i=0;i<n;i++)
        {
            if(newInterval[0] > intervals[i][1])
                answer.push_back(intervals[i]);
            else if(newInterval[1] < intervals[i][0] )
            {
                if(flag==0)
                answer.push_back(newInterval);
                answer.push_back(intervals[i]);
                flag=1;
            }
            else
            {
                newInterval[0]= min(newInterval[0],intervals[i][0]);
                 newInterval[1]= max(newInterval[1],intervals[i][1]);
                
            }
        }
        if(flag==0)
            answer.push_back(newInterval);
            return answer;
    }
};
