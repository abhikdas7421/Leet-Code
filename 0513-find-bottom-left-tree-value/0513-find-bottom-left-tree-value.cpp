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
        que.emplace(root);
        
        int ans = root->val;
        
        while(!que.empty()) {
            TreeNode* node = que.front(); que.pop();
            ans = node->val;
            
            if(node->right) {
                que.emplace(node->right);
            }
            if(node->left) {
                que.emplace(node->left);
            }
        }
        
        return ans;
    }*/
    
    // Approach 2:- (Using BFS -> level by level processsing)
    int findBottomLeftValue(TreeNode* root) {
        
        queue<TreeNode*> que;
        que.emplace(root);
        
        int bottomLeft = root->val;
        
        while(!que.empty()) {
            int n = que.size();
            
            while(n--) {
                TreeNode* node = que.front(); que.pop();
                bottomLeft = node->val;
                
                if(node->right) {
                    que.emplace(node->right);
                }
                if(node->left) {
                    que.emplace(node->left);
                }
            }
           
        }
        
        return bottomLeft;
    }
    
    
    // Approach 3:- Using DFS
    /*void solve(TreeNode* node, int currDepth, int &depth, int &leftMostValue) {
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
    }*/
};