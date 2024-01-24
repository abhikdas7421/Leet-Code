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
    int solve(TreeNode* root, vector<int> &freq) {
        if(root == nullptr) {
            return 0;
        }
        // if(root->left == nullptr && root->right == nullptr) {
        //     freq[root->val]++;
        //     int oddCount = 0;
        //     for(int i = 1; i < 10; i++) {
        //         if(freq[i]%2  != 0) {
        //             oddCount++;
        //         }
        //     }
        //     freq[root->val]--;
        //     if(oddCount > 1) {
        //         return 0;
        //     } 
        //     return 1;
        // }
        
        freq[root->val]++;
        
        if(root->left == NULL && root->right == NULL) {
            int oddCount = 0;
            
            for(int i = 1; i < 10; i++) {
                
                if(freq[i]%2 != 0) {
                    oddCount++;
                }
            }
            
            freq[root->val]++;
            
            if(oddCount > 1) {
                return 0;
            }
            return 1;
        }
        
        int l = solve(root->left, freq);
        int r = solve(root->right, freq);
        
        freq[root->val]--;
        
        return l+r;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10, 0);
        int ans = solve(root, freq);
        return ans;
    }
};