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
    ListNode* midOfLL(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* mid = slow->next;
        slow->next = nullptr;
        return mid;
    }
    
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while(curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        return prev;
    }
    
    void reorderList(ListNode* head) {
        ListNode* head1 = head;
        ListNode* head2 = reverseLL(midOfLL(head));
        
        bool isH1 = true;
        
        while(head1 != nullptr || head2 != nullptr) {
            
            if(isH1) {
                ListNode* next = head1->next;
                head1->next = head2;
                head1 = next;
            }
            else {
                ListNode* next = head2->next;
                head2->next = head1;
                head2 = next;
            }
            
            isH1 = !isH1;
        }
    }
};