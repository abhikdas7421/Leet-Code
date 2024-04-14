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
    // Approach:- 1 | T.C:- O(n) | S.C:- O(h)
    int solve(TreeNode* root, bool isLeft) {
        if(root == nullptr) {
            return 0;
        }
        
        if(root->left == nullptr && root->right == nullptr && isLeft) {
            return root->val;
        }
        
        int left = solve(root->left, true);
        int right = solve(root->right, false);
        
        return left+right;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = solve(root, false);
        return sum;
    }
};