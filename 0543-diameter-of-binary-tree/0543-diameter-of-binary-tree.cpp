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
    // Approach:- 1
    /*int height(TreeNode* root) {
        if(root == NULL) return 0;
        
        int left = height(root->left);
        int right = height(root->right);
        
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        
        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);
        int op3 = height(root->left) + height(root->right);
        
        return max(op1, max(op2, op3));
    }*/
    
    // Approach:- 2
    /*pair<int, int> diameterFast(TreeNode* root) {
        if(root == NULL) {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }
        
        pair<int, int> left = diameterFast(root->left);
        pair<int, int> right = diameterFast(root->right);
        
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second;
        
        pair<int, int> ans;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(left.second, right.second) + 1;
        
        return ans;
        
        
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterFast(root).first;
    }*/
    
    // Approach :- 3
    int solve(TreeNode* root, int &result) {
        if(root == NULL) {
            return 0;
        }
        
        int left = solve(root->left, result);
        int right = solve(root->right, result);
        
        result = max(result, left+right);
        return max(left, right) + 1;
    
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        solve(root, result);
        
        return result;
    }
    
};