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
    ListNode* helper(ListNode* head, int n, int &count) {
        if(head == nullptr) {
            return nullptr;
        }
        
        head->next = helper(head->next, n, count);
        count++;
        
        if(count == n) {
            ListNode* temp = head;
            head = head->next;
            temp->next = nullptr;
            return head;
        }
        
        return head;
        
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* newHead = helper(head, n, count);
        return newHead;
    }
};