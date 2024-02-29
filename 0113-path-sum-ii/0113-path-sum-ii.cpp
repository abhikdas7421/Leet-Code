/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     void hasPathSum(TreeNode* root, int targetSum, vector<int> &path, vector<vector<int>> &ans) {
        if(!root) return;
         
        
        path.push_back(root->val);
         
        // leaf node
        if(root->val == targetSum &&root->left == NULL && root->right == NULL) ans.push_back(path);
         
        hasPathSum(root->left, targetSum-root->val, path, ans);
        hasPathSum(root->right, targetSum-root->val, path, ans);
        path.pop_back();
        
       
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        hasPathSum(root, targetSum, path, ans);
        return ans;
        
        
    }
};