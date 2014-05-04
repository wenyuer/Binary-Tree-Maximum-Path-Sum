/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode *root) 
    {
        int maxsum = -9999999;
        maxSum(root,maxsum);
        return maxsum;
    }
    int maxSum(TreeNode *root, int &maxsum) {
        if(root == NULL)
            return -9999999;
     //   if(root->left == NULL && root->right == NULL)
     //       return root->val;
            
        int maxleft;
        int maxright;
        int maxpoint = 0;
        
     //   if(root->left != NULL)
            maxleft = maxSum(root->left,maxsum);
     //   if(root->right != NULL)
            maxright = maxSum(root->right,maxsum);
            
        if(maxleft > maxright)
        {
            if(root->val < root->val + maxleft)
                maxpoint = root->val + maxleft;
            else
                maxpoint = root->val;
        }
        else
        {
            if(root->val < root->val + maxright)
                maxpoint = root->val + maxright;
            else
                maxpoint = root->val;
        }
            
        if(maxsum < maxleft + maxright + root->val)
            maxsum = maxleft + maxright + root->val;
        if(maxsum < maxpoint)
            maxsum = maxpoint;
            
        return maxpoint;
    }
};