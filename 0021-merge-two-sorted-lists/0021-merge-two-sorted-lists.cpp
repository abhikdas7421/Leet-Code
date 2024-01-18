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
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        
        // dummy node;
        ListNode* head = new ListNode(-1);
        ListNode* tail = head;
        
        while(list1 != nullptr && list2 != nullptr) {
            
            if(list1->val < list2->val) {
                ListNode* temp = list1;
                list1 = list1->next;
                temp->next = nullptr;
                
                tail->next = temp;
                tail = temp;
            }
            else {
                ListNode* temp = list2;
                list2 = list2->next;
                temp->next = nullptr;
                
                tail->next = temp;
                tail = temp;
            }
        }
        
        if(list1 != nullptr) {
            tail->next = list1;
        }
        
        if(list2 != nullptr) {
            tail->next = list2;
        }
        
        ListNode *dummy = head;
        head = head->next;
        dummy->next = nullptr;
        
        return head;
        
    }
};