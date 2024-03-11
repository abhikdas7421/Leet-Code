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
    int maxVal(TreeNode* root) {
        TreeNode* temp = root;
        
        while(temp->right != nullptr) {
            temp = temp->right;
        }
        
        return temp->val;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        // base case
        if(root == nullptr) return nullptr;
        
        if(root->val == key) {
            // 4 cases
            
            if(root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            else if(root->left == nullptr && root->right != nullptr) {
                TreeNode* child = root->right;
                root->right = nullptr;
                delete root;
                return child;
            }
            else if(root->left != nullptr && root->right == nullptr) {
                TreeNode* child = root->left;
                root->left = nullptr;
                delete root;
                return child;
            }
            else {
                int inorderPre = maxVal(root->left);
                root->val = inorderPre;
                root->left = deleteNode(root->left, inorderPre);
                return root;
            }
        }
        else if(key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else if(key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        
        return root;
    }
};