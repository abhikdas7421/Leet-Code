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
    int getLen(ListNode* head) {
        int len = 0;
        while(head != nullptr) {
            ++len;
            head = head->next;
        }
        
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int len = getLen(head);
        if(head == 0 || head->next == 0 || k == 0 || len == k) {
            return head;
        }
        
        int r =len - (k%len);
       
        
        
        ListNode* temp = head;
        int i = 1;
        while(i < r) {
            temp = temp->next;
            i++;
        }
        
        ListNode *list1 = head;
        ListNode *list2 = temp->next;
        ListNode *tail2 = list2;
        temp->next = nullptr;
        
        if(!tail2) {
            return list1;
        }
        
        while(tail2->next) {
            tail2 = tail2->next;
        }
        
        tail2->next = list1;
        return list2;
    }
};