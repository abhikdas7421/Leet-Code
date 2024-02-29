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
        if(root == NULL) {
           
            return;
        }
         
        // leaf node
        if(root->left == NULL && root->right == NULL) {
            if(root->val == targetSum) {
                path.push_back(root->val);
                ans.push_back(path);
                path.pop_back();
            }
            
            return;
        }
         
        path.push_back(root->val);
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