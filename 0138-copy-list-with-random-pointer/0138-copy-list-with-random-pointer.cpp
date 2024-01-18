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
    Node* copyRandomList(Node* head) {
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
};