/*
Time complexity :  O(N)
Space complexity : O(N)
*/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> end_idx(26, 0);
        for(int i = 0; i < S.length(); ++i)
            end_idx[S[i] - 'a'] = i;
        
        vector<int> result;
        int start = 0, end = 0;
        for(int i = 0; i < S.length(); ++i){
            end = max(end, end_idx[S[i] - 'a']);
            if(i == end){ // all the characters of current partition included
                result.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return result;
    }
};
