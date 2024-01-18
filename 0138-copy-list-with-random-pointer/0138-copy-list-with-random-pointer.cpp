/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
    //Approach 1 :- Recursive Approach || T.C = O(n) and S.C = O(n)
    /* Node* solve(Node* head, unordered_map<Node*, Node*> &mp) {
        if(head == 0) return head;
        
        Node* newHead = new Node(head->val);
        mp[head] = newHead;
        newHead->next = solve(head->next, mp);
        
        if(head->random) {
            newHead->random = mp[head->random];
        }
        return newHead;
    }
    
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        return solve(head, mp);
        
    }
    */
    
    //Approach 2:- Iterative Approach || T.C = O(n) and S.C = O(n)
    /* Node* copyRandomList(Node* head) {
        // dummy node
        Node *newHead = new Node(-1);
        Node* newTail = newHead;
        
        unordered_map<Node*, Node*> mp;
        
        Node* temp = head;
        while(temp != 0) {
            newTail->next = new Node(temp->val);
            newTail = newTail->next;
            
            mp[temp] = newTail;
            temp = temp->next;
        }
        
        // remove dummy node;
        Node* dummy = newHead;
        newHead = newHead->next;
        dummy->next = 0;
        
        temp = head;
        Node* newTemp = newHead;
        while(temp != 0) {
            newTemp->random = mp[temp->random];
            temp = temp->next;
            newTemp = newTemp->next;
        }
        
        return newHead;
    }
    */
    
    // Approach 3 :- Withour using map || T.C = O(n) and S.C = O(1)
    Node* copyRandomList(Node* head) {
        if(!head) return 0;
        
        // Step 1 :- Clone A -> A'
        Node* it = head; // Iterate over old head
        while(it) {
            Node* clonedNode = new Node(it->val);
            clonedNode->next = it->next;
            it->next = clonedNode;
            it = it->next->next;
        }
        
        // Step 2 :- Assign random links of A' with the help of old A
        it = head;
        while(it) {
            Node *clonedNode = it->next;
            clonedNode->random = it->random ? it->random->next : nullptr;
            it = it->next->next;
        }
        
        // Step 3 :- Detach A' from A
        it = head;
        Node* clonedHead = it->next;
        while(it) {
            Node *temp = it->next;
            it->next = it->next->next;
            
            if(temp->next) {
                temp->next = temp->next->next;
            }
            it = it->next;
            
        }
        return clonedHead;
    }
};