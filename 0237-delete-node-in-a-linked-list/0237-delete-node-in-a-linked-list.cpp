/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        ListNode* current = node;
        
        while(current != nullptr) {
            
            if(current->next->next == nullptr) {
                current->val = current->next->val;
                current->next = nullptr;
            }
            else {
                current->val = current->next->val;
            }
            
            
            current = current->next;
        }
        
    }
};