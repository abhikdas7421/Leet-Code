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
    void path(TreeNode* root, string str, vector<string> &ans) {
        if(root == NULL) {
            return;
        }
        
        
        if(!str.empty()) {
            str += "->";
        }
        str += to_string(root->val);
        
        // leaf Node
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(str);
            return;
        }
        
        path(root->left, str, ans);
        path(root->right, str, ans);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string str;
        path(root, str, ans);
        return ans;
    }
};