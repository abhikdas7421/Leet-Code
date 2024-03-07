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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>>que;
        
        que.push({root, {0, 0}});
        
        while(!que.empty()) {
            auto temp = que.front(); que.pop();
            
            TreeNode* frontNode = temp.first;
            int row = temp.second.first;
            int col = temp.second.second;
            
            mp[col][row].insert(frontNode->val);
            
            if(frontNode->left) {
                que.push({frontNode->left, {row+1, col-1}});
            }
            
            if(frontNode->right) {
                que.push({frontNode->right, {row+1, col+1}});
            }
        }
        
        for(auto p : mp) {
            vector<int> ans;
            for(auto q : p.second) {
                ans.insert(ans.end(), q.second.begin(), q.second.end());
            }
            result.push_back(ans);
        }
        
        return result;
    }
};