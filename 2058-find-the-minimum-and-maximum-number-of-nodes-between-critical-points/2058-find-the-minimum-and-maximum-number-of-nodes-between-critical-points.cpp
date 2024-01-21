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
    int findLen(ListNode* head) {
        int len = 0;
        while(head != nullptr) {
            len++;
            head = head->next;
        }
        
        return len;
    }
    
    bool isCritical(int prev, int curr, int next) {
        
        if((curr > prev && curr > next) || (curr < prev && curr < next)) {
            return true;
        }
        
        return false;
    }
    
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int length = findLen(head);
        vector<int> ans(2,-1);
        
        if(length < 4) {
            return ans;
        }
        
        ListNode* prev = head;
        ListNode* curr = prev->next;
        
        int i = 2;
        int fastCriticalPoint = -1;
        int lastCritiCalPoint = fastCriticalPoint;
        int minDistance = INT_MAX;
        
        while(curr->next != nullptr) {
            ListNode *currNext = curr->next;
            
            if(isCritical(prev->val, curr->val, currNext->val)) {
                
                int currCriticalPoint = i;
                if(fastCriticalPoint == -1) {
                    fastCriticalPoint = currCriticalPoint;
                    lastCritiCalPoint = currCriticalPoint;
                }
                else {
                    minDistance = min(minDistance, (currCriticalPoint-lastCritiCalPoint));
                    lastCritiCalPoint = currCriticalPoint;
                }
            }
            i++;
            prev = curr;
            curr = currNext;
            
        }
        
        minDistance = (minDistance == INT_MAX) ? -1 : minDistance;
        int maxDistance = (lastCritiCalPoint-fastCriticalPoint == 0) ? -1 : (lastCritiCalPoint-fastCriticalPoint);
    
        ans[0] = minDistance;
        ans[1] = maxDistance;
        
        return ans;
        
    }
};