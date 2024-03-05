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
    // Approach 1:- BFS Using extra space(map) | T.C:- O(n) | S.C:- O(h)
    /*vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) {
            return ans;
        }
        
        map<int, int> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            auto temp = q.front(); q.pop();
            
            TreeNode* frontNode = temp.first;
            int x = temp.second;
            mp[x] = frontNode->val;
            
            if(frontNode->left) {
                q.push({frontNode->left, x+1});
            }
            if(frontNode->right) {
                q.push({frontNode->right, x+1});
            }
        }
        
        for(auto p : mp) {
            ans.push_back(p.second);
        }
        return ans;
    }*/
    
    // Approach 2:- BFS (Without extra space) | T.C:- O(n) | S.C:- O(1)
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) {
            return ans;
        }
        
        queue<TreeNode*> que;
        que.push(root);
        
        while(!que.empty()) {
            int n = que.size();
            
            for(int i = 0; i < n; i++) {
                TreeNode* temp = que.front(); que.pop();
                
                if(i == 0) {
                    ans.push_back(temp->val);
                }
                
                if(temp->right) {
                    que.push(temp->right);
                }
                
                if(temp->left) {
                    que.push(temp->left);
                }
                
            }
        }
        return ans;
    }
};















