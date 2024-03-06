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
    // Brute Force
    // Approach:- 1 | T.C-> O(n^2) | S.C -> O(1)
    /*int height(TreeNode* root) {
        if(root == NULL) return 0;
        
        int left = height(root->left);
        int right = height(root->right);
        
        return max(left, right)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        // base case
        if(root == NULL) return true;
        
        // 1 case solve  
        bool curr = abs(height(root->left)-height(root->right)) <= 1 ? true : false;
        
        // recursion
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
       
        
        return (left && right && curr);
    }*/
    
    // Approach:- 2 | T.C -> O(n) | S.C -> O(1)
    int height(TreeNode* root, bool &isbalanced) {
        if(root == nullptr) {
            return 0;
        }
        
        int leftHeight = height(root->left, isbalanced);
        int rightHeight = height(root->right, isbalanced);
        
        if(isbalanced && abs(leftHeight-rightHeight) > 1) {
            isbalanced = false;
        }
        
        return max(leftHeight, rightHeight)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        bool isbalanced = true;
        height(root, isbalanced);
        
        return isbalanced;
    }
};