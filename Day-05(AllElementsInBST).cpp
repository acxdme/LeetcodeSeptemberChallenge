/*
Time complexity : O( N log N) , where N= (m+n)
Space complexity : O(N)
My approach : Declare globally a vector v , traverse both the BST and store them in an array, sort the array and return the result.
              (also you can store the inorder traversal in seperate arrays and then merge them to obtain final answer in O(n+m) time )
*/

class Solution {
public:
    vector<int> answer;
   void helper(TreeNode* root)
    {
        if(root==NULL)
            return ;
       answer.push_back(root->val);
       helper(root->left);
       helper(root->right);
        
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        
        helper(root1);
        helper(root2);
        
        sort(answer.begin(),answer.end());
        return answer;
    }
};
