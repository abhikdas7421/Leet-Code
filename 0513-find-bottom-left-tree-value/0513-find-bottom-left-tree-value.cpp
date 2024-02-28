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
    // Approach 1:- (Using BFS)
    /*int findBottomLeftValue(TreeNode* root) {
        
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
    }*/
    
    // Approach 2:- Using DFS
    void solve(TreeNode* node, int currDepth, int &depth, int &leftMostValue) {
        if(node == NULL) {
            return;
        }
        
        if(currDepth > depth) {
            leftMostValue = node->val;
            depth = currDepth;
        }
        
        solve(node->left, currDepth+1, depth, leftMostValue);
        solve(node->right, currDepth+1, depth, leftMostValue);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        int depth = 0;
        int currDepth = 1;
        int leftMostValue = root->val;
        
        solve(root, currDepth, depth, leftMostValue);
        
        return leftMostValue;
    }
};