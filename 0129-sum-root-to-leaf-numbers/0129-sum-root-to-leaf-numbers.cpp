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
    long long ans = 0;
    string str;
    
    void dfs(TreeNode* root) {
        if(!root) return;
        
        str.push_back(root->val+'0');
        
        if(!root->left && !root->right) {
            int path = stoi(str);
            ans += path;
        }
        
        dfs(root->left);
        dfs(root->right);
        str.pop_back();
        
    }
    
    int sumNumbers(TreeNode* root) {
        dfs(root);
        return ans;
    }
};