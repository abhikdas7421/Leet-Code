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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> que;
        que.emplace(root);
        
        int level = 0;
        int prev;
        
        while(!que.empty()) {
            
            int n = que.size();
            
            for(int i = 0; i < n; i++) {
                TreeNode* curr = que.front(); que.pop();
                
                if(level%2 == 0) { // even level
                    
                    if((i == 0 && curr->val % 2 != 0) || (i != 0 && curr->val % 2 != 0 && curr->val > prev)) {
                        prev = curr->val;
                    }
                    else {
                        return false;
                    }

                }
                else { // odd level
                    
                    if((i == 0 && curr->val % 2 == 0) || (i != 0 && curr->val % 2 == 0 && curr->val < prev)) {
                        prev = curr->val;
                    }
                    else {
                        return false;
                    }
                    
                }
                
                if(curr->left) {
                    que.emplace(curr->left);
                }
                
                if(curr->right) {
                    que.emplace(curr->right);
                }
            }
            
            level++;
        }
        
        return true;
    }
};


































