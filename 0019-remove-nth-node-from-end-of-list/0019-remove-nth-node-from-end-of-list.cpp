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
    // Approach 1 :- (Two pass) 
    /*ListNode* removeNthFromEnd(ListNode* head, int n) {
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
    
        int res = count-n-1; temp = head; 
        while(temp != nullptr && res--) {
            temp = temp->next;
        }
        
        ListNode* deleteNode = temp->next;
        temp->next = temp->next->next;
        
        deleteNode->next = nullptr;
        delete deleteNode;
        
        return head;
    }*/
    
    // Approach 2 :- (recursion)
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
    
    // Approach 3 :- (Two pointer-> One Pass requried)
    /*ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }
        
        if(fast == nullptr) {
            head = head->next;
            slow->next = nullptr;
            delete slow;
            
            return head;
        }
        
        while(fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode* deleteNode = slow->next;
        slow->next = slow->next->next;
        deleteNode->next = nullptr;
        delete deleteNode;
        
        return head;
    }*/
};