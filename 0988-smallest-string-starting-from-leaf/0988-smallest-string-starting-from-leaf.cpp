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
    // Approach:- 1 | (Using DFS) | O(n^2)
    /*void dfs(TreeNode* root, string currStr, string &ans) {
        if(root == nullptr) return;
        
        currStr = char(root->val+'a') + currStr; // O(length of currSTr)
        
        if(!root->left&& !root->right) {
            if(ans == "" || ans > currStr) {
                ans = currStr;
            }
            
            return;
        }
        
        dfs(root->left, currStr, ans);
        dfs(root->right, currStr, ans);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        dfs(root, "", ans);
        
        return ans;
    }*/
    
    // Approach:- 2 | (Using BFS) | O(n^2)
    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        
        queue<pair<TreeNode*, string>> que;
        
        que.push({root, string(1, char(root->val+'a'))});
        
        while(!que.empty()) {
            pair<TreeNode*, string> p = que.front(); 
            que.pop();
            
            TreeNode* node = p.first;
            string curr = p.second;
            
            if(!node->left && !node->right) {
                if(ans == "" || ans > curr) {
                    ans = curr;
                }
            }
            
            if(node->left) {
                que.push({node->left, (char(node->left->val+'a') + curr)});
            }
            
            if(node->right) {
                que.push({node->right, (char(node->right->val+'a') + curr)});
            }
        }
        
        return ans;
        
    }
};