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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode* a_node = nullptr;
        ListNode* temp = list1;
        while(a--) {
            a_node = temp;
            temp = temp->next;
            
        }
        
        ListNode* b_node = list1;
        while(b--) {
            b_node = b_node->next;
        }
        
        ListNode* tail2 = list2;
        while(tail2->next != nullptr) {
            tail2 = tail2->next;
        }
        
        tail2->next = b_node->next;
        
        if(a_node != nullptr) {
            a_node->next = list2;
            return list1;
        }
        else {
            return list2;
        }
        
        
    }
};