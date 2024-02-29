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
    
    void dfs(TreeNode* root, string &str, int &ans) {
        if(!root) return;
        
        str.push_back(root->val+'0');
        
        if(!root->left && !root->right) {
            int path = stoi(str);
            ans += path;
        }
        
        dfs(root->left, str, ans);
        dfs(root->right, str, ans);
        
        str.pop_back();
        
    }
    
    int sumNumbers(TreeNode* root) {
        string str;
        int ans = 0;
        
        dfs(root, str, ans);
        return ans;
    }
};