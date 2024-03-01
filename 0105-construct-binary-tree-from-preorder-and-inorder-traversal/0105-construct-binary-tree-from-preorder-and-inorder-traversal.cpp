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
    int findElement(vector<int> &arr, int start, int end, int targetElement) {
        for(int i = start; i <= end; i++) {
            if(arr[i] == targetElement) {
                return i;
            }
        }
        
        return -1;
    }
    
    unordered_map<int, int> mp;
    
    TreeNode* buildTreeHelper(vector<int> &pre, vector<int> &in, int size, int &preIndex, int inStart, int inEnd) {
        // base case
        if(preIndex >= size || inStart > inEnd) {
            return nullptr;
        }
        
        // Step A: root
        int element = pre[preIndex++];
        TreeNode* root = new TreeNode(element);
        // int pos = findElement(in, inStart, inEnd, element);
        int pos = mp[element];
        
        
        // Step B: root->left
        root->left = buildTreeHelper(pre, in, size, preIndex, inStart, pos-1);
        
        //Step C: root->right
        root->right = buildTreeHelper(pre, in, size, preIndex, pos+1, inEnd);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int size = preorder.size();
        int preIndex = 0;
        int inStart = 0;
        int inEnd = size-1;
        
        for(int i = 0; i < size; i++) {
            mp[inorder[i]] = i;
        }
        
        TreeNode* root = buildTreeHelper(preorder, inorder, size, preIndex, inStart, inEnd);
        
        return root;
    }
};