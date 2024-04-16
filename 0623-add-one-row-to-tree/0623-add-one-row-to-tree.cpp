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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth == 1) {
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        
        if(root == nullptr) return nullptr;
        
        if(depth == 2) {
            TreeNode* leftNode = root->left;
            TreeNode* rightNode = root->right;
            
            TreeNode* newNode1 = new TreeNode(val);
            newNode1->left = leftNode;
            
            TreeNode* newNode2 = new TreeNode(val);
            newNode2->right = rightNode;
            
            root->left = newNode1;
            root->right = newNode2;
            
            return root;
        }
        
        root->left = addOneRow(root->left, val, depth-1);
        root->right = addOneRow(root->right, val, depth-1);
        
        return root;
        
    }
};