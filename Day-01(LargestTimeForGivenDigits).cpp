/*
Time complexity : O(1)
space complexity : O(1)
My approach : go through all the combinations and find the maximum possible time which is in valid format.
*/
//Method-1
class Solution {
public:
    
    set<string> st;
     void allPermutations(string a,int l, int r)
     {
         if(l==r)
         {
            
            st.insert(a);
         }
         else
         {
             for(int i=l;i<=r;i++)
             {
                 swap(a[l],a[i]);
                 
                 allPermutations(a,l+1,r);
                 
                 swap(a[l],a[i]);
             }
         }
     }
    
    string largestTimeFromDigits(vector<int>& A) {
        string ans;
        
        if(A[0]>2 and A[1]>2 and A[2]>2 and A[3]>2)
            return ans;
        
        string imm = to_string(A[0]) +to_string(A[1]) +to_string(A[2]) +to_string(A[3]);
         allPermutations(imm, 0, 3);
        
        string result;
        for(string it : st)
        {
            if(it<= "2359" and it>result and it[2] < '6')
                result =it; 
        }
         if(result.size()==4)
         result += ':';
         swap(result[4],result[3]);
         swap(result[3],result[2]);

        return result;
    }
};

//Method-2
class Solution {
public:
      string largestTimeFromDigits(vector<int>& A) {
        string result;
        for(int i = 0; i < 4; ++i)
        {
            for(int j = 0; j < 4; ++j)
            {
                for(int k = 0; k < 4; ++k)
                {
                    if(i == j || j == k || k == i)
                        continue;
                    string hh = to_string(A[i]) + to_string(A[j]);
                    string mm = to_string(A[k]) + to_string(A[6-i-j-k]);
                    string _time = hh + ":" + mm;
                    if(hh < "24" && mm < "60" && _time > result)
                        result = _time;
                }
            }
        }
        return result;
    }
};
