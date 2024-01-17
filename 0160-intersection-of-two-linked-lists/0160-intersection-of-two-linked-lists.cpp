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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA;
        ListNode *b = headB;
        
        while(a->next != nullptr && b->next != nullptr) {
            if(a == b) {
                return a;
            }
            
            a = a->next;
            b = b->next;
        }
        
        if(a->next == nullptr) {
            // b LL is bigger than a LL
            int bLen = 0;
            
            while(b->next != nullptr) {
                bLen++;
                b = b->next;
            }
            
            while(bLen--) {
                headB = headB->next;
            }
        }
        else {
            // a LL is bigger than b LL
            int aLen = 0;
            
            while(a->next != nullptr) {
                aLen++;
                a = a->next;
            }
            
            while(aLen--) {
                headA = headA->next;
            }
        }
        
        while(headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
            
        return headA;
        
    }
};