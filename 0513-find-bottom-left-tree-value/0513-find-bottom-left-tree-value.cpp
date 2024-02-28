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
    int findBottomLeftValue(TreeNode* root) {
        
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);
        
        int ans = root->val;
        
        while(!que.empty()) {
            TreeNode* node = que.front(); que.pop();
            
            if(node == NULL) {
                if(!que.empty()) {
                    ans = que.front()->val;
                    que.push(NULL);
                }
                continue;
            }
            
            if(node->left) {
                que.push(node->left);
            }
            if(node->right) {
                que.push(node->right);
            }
        }
        
        return ans;
    }
};