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
    // Approach:- 1 | T.C:- O(n) | S.C:- O(n)
    /*void inOrder(TreeNode* root, vector<int> &v) { //LNR
        if(root == nullptr) return;
        
        inOrder(root->left, v);
        v.push_back(root->val);
        inOrder(root->right, v);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        inOrder(root, arr);
        
        return arr[k-1];
    }*/
    
    
   // Approach:- 2
    void solve(TreeNode* root, int &k, int& ans) {
        // base case
        if(root == NULL) {
            return;
        }
        
        // Left
        solve(root->left, k, ans);
        
        k--;
        if(k == 0) {
            ans = root->val;
            return;
        }
        
        solve(root->right, k, ans);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        solve(root, k, ans);
        return ans;
    }
    
};









