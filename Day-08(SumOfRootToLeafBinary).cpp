/*
Time complexity : O(N)
Space complexity : O(1)
My approach : So, the nodes represent the bits (0,1) where as we go deeper in tree we get a less significant digit of the binary number.
              The catch here is to left shift the binary number so formed by 1 and addinto it the current root->val. (sum = (sum<<1) + root->val);
              When a leaf node occurs return the sum and when a node is NULL return 0 .
*/

class Solution {
public:
      
     int  helper(TreeNode* root, int sum)
    {
       if(root==NULL)
           return 0;
        sum = (sum<<1 ) + root->val;
       if(root->right == NULL and root->left == NULL)
           return sum;
        return helper(root->left,sum) + helper(root->right,sum);
        
    }
    int sumRootToLeaf(TreeNode* root) 
    {
       int result =0;
        if(root==NULL)
            return result;
        result = helper(root,0);  
        
      return result;
        
    }
};
