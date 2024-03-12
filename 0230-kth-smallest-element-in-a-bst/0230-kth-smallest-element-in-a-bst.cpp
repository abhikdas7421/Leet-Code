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
    void inOrder(TreeNode* root, vector<int> &v) { //LNR
        if(root == nullptr) return;
        
        inOrder(root->left, v);
        v.push_back(root->val);
        inOrder(root->right, v);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        inOrder(root, arr);
        
        int ans = -1;
        
        for(int i = 0; i < k; i++) {
            ans = arr[i];
        }
        
        return ans;
    }
};