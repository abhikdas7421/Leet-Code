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
        
        // ListNode* curr = head;
        head->next = helper(head->next, n, count);
        count++;
        
        ListNode* newHead;
        if(count == n) {
            newHead = head->next;
            head->next = nullptr;
            return newHead;
        }
        
        return head;
        
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* newHead = helper(head, n, count);
        return newHead;
    }
};