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
    void dfs(TreeNode* root, string currStr, string &ans) {
        if(root == nullptr) return;
        char ch = root->val+'a';
        currStr = (ch) + currStr;
        
        if(root->left == nullptr && root->right == nullptr) {
            if(ans == "" || ans > currStr) {
                ans = currStr;
            }
            
            return;
        }
        
        dfs(root->left, currStr, ans);
        dfs(root->right, currStr, ans);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        dfs(root, "", ans);
        
        return ans;
    }
};