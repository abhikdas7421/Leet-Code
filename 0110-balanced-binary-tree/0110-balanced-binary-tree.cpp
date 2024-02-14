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
    int height(TreeNode* root) {
        if(root == nullptr) return 0;
        
        return 1 + max(height(root->left), height(root->right));
    }
public:
    // Approach 1:- T.C - > O(n^2) | S.C -> O(n);
    /*bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        
        bool diff = abs(height(root->left) - height(root->right)) <= 1;
        
        return (left && right && diff);
    }*/
    
    // Approach 2:- 
    pair<bool, int> isBalancedFast(TreeNode* root) {
        if(root == nullptr) {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        
        pair<bool, int> left = isBalancedFast(root->left);
        pair<bool, int> right = isBalancedFast(root->right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool diff = abs(left.second-right.second) <= 1;
        
        pair<bool, int> ans;
        ans.first = (leftAns && rightAns && diff);
        ans.second = 1 + max(left.second, right.second);
        
        return ans;
    }
    
    bool isBalanced(TreeNode* root) {
        return isBalancedFast(root).first;
    }
};