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
    ListNode* reverseLL(ListNode* head) {
        ListNode* left = nullptr;
        ListNode* curr = head;
        
        while(curr != nullptr) {
            ListNode* right = curr->next;
            
            curr->next = left;
            left = curr;
            curr = right;
        }
        
        return left;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        head = reverseLL(head);
        
        stack<int> st;
        st.push(INT_MAX);
        vector<int> ans;
        
        while(head != nullptr) {
            
            while(st.top() <= head->val) {
                st.pop();
            }
            int greater = st.top()%INT_MAX;
            ans.push_back(greater);
            st.push(head->val);
            head = head->next;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};