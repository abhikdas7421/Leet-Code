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
    void dfs(TreeNode* root, string currSum, int &sum) {
        if(root == nullptr) {
            return;
            
        }
        
        if(root->left == nullptr && root->right == nullptr) {
            char ch = root->val+'0';
            currSum += ch;
            
            sum += stoi(currSum);
            return;
        }
        
        char ch = root->val + '0';
        dfs(root->left, currSum+ch, sum);
        dfs(root->right, currSum+ch, sum);
        
        
    }
    
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        dfs(root, "", sum);
        
        return sum;
    }
};