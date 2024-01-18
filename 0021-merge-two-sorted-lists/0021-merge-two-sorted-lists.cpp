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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        
        // dummy node;
        ListNode* head = new ListNode(-1);
        ListNode* tail = head;
        
        while(temp1 != nullptr && temp2 != nullptr) {
            
            if(temp1->val < temp2->val) {
                ListNode* temp = temp1;
                temp1 = temp1->next;
                temp->next = nullptr;
                
                tail->next = temp;
                tail = temp;
            }
            else {
                ListNode* temp = temp2;
                temp2 = temp2->next;
                temp->next = nullptr;
                
                tail->next = temp;
                tail = temp;
            }
        }
        
        if(temp1 != nullptr) {
            tail->next = temp1;
        }
        
        if(temp2 != nullptr) {
            tail->next = temp2;
        }
        
        ListNode *dummy = head;
        head = head->next;
        dummy->next = nullptr;
        
        return head;
        
    }
};