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
    // Using DFS
    /*bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr || q == nullptr) return false;
        
        if(p->val != q->val) return false;
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }*/
    
    // Using BFS
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        
        if(p == nullptr || q == nullptr) return false;
        
        queue<TreeNode*> que1;
        queue<TreeNode*> que2;
        
        que1.push(p);
        que2.push(q);
        
        while(!que1.empty() && !que2.empty()) {
            TreeNode* node1 = que1.front(); que1.pop();
            TreeNode* node2 = que2.front(); que2.pop();
            
            if(node1->val != node2->val) return false;
            
            if(node1->left != nullptr && node2->left != nullptr) {
                que1.push(node1->left);
                que2.push(node2->left);
            }
            else if(node1->left != nullptr || node2->left != nullptr) {
                return false;
            }
            
            if(node1->right != nullptr && node2->right != nullptr) {
                que1.push(node1->right);
                que2.push(node2->right);
            }
            else if(node1->right != nullptr || node2->right != nullptr) {
                return false;
            }
            
        }
        
        return true;
    }
};












