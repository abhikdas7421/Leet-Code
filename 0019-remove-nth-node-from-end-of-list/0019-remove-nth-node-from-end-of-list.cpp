/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Approach 1 :- 
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int count = 0;
        
        while(temp != nullptr) {
            temp = temp->next;
            count++;
        }
        
        
        if(count == n) {
            ListNode* newHead = head->next;
            head->next = nullptr;
            delete head;
            
            return newHead;
        }
    
        int res = count-n;
        temp = head;    
        res--;
        while(temp != nullptr) {
            if(res == 0) {
                break;
            }
            temp = temp->next;
            res--;
        }
        
        ListNode* deleteNode = temp->next;
        temp->next = temp->next->next;
        
        // deleteNode->next = nullptr;
        // delete deleteNode;
        
        return head;
    }
};