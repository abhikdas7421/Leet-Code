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
    void storeInorder(TreeNode* root, vector<int> &v) {
        if(root == nullptr) return;
        
        // Left
        storeInorder(root->left, v);
        
        // Node
        v.push_back(root->val);
        
        // Right
        storeInorder(root->right, v);
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        storeInorder(root, v);
        
        int s = 0;
        int e = v.size()-1;
        
        while(s < e) {
            
            if(v[s] + v[e] == k) {
                return true;
            }
            else if(v[s] + v[e] > k) {
                e--;
            }
            else {
                s++;
            }
        }
        
        return false;
    }
};