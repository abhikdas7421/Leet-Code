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
    bool solve(TreeNode* root, long long int lower_bound, long long int upper_bound) {
        // base case
        if(root == nullptr) {
            return true;
        }
        
        if(root->val > lower_bound && root->val < upper_bound) {
            bool leftAns = solve(root->left, lower_bound, root->val);
            bool rightAns = solve(root->right, root->val, upper_bound);
            return leftAns && rightAns;
        }
        else {
            return false;
        }
    }
    
    bool isValidBST(TreeNode* root) {
        long long int lower_bound = LLONG_MIN;
        long long int upper_bound = LLONG_MAX;
        return solve(root, lower_bound, upper_bound);
    }
};