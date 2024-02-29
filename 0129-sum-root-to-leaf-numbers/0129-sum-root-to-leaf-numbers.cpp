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
    // Approach 1
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
    
    // Approach 2
    /*int dfs2(TreeNode* root, int ans) {
        if(root == NULL) return 0;
        
        ans = ans*10 + root->val;
        if(!root->left && !root->right) {
            return ans;
        }
        
        int left = dfs2(root->left, ans);
        int right = dfs2(root->right, ans);
        
        return left+right;
    }
    
    int sumNumbers(TreeNode* root) {
        
        return dfs2(root, 0);
    }*/
};