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
    
    TreeNode* buildTreeHelper(vector<int> &in, vector<int> &post, int size, int &postIndex, int inStart, int inEnd) {
        // base case
        if(postIndex < 0 || inStart > inEnd) {
            return nullptr;
        }
        
        // Step A: root
        int element = post[postIndex--];
        TreeNode* root = new TreeNode(element);
        int pos = findElement(in, inStart, inEnd, element);
        
        // Step B: root->right
        root->right = buildTreeHelper(in, post, size, postIndex, pos+1, inEnd);
        
        // Step C: root->left
        root->left = buildTreeHelper(in, post, size, postIndex, inStart, pos-1);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        int postIndex = size-1;
        int inStart = 0;
        int inEnd = size-1;
        
        TreeNode* root = buildTreeHelper(inorder, postorder, size, postIndex, inStart, inEnd);
        
        return root;
    }
};