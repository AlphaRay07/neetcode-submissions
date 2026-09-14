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
        if(!head) return nullptr;
        Node* cur=head;
        Node* newnode= new Node(0);
        Node* newhead=newnode;
        unordered_map<Node*,Node*> hash;
        while(head->next){
            newnode->val=head->val;
            newnode->next= new Node(0);
            hash[head]=newnode;
            newnode=newnode->next;
            head=head->next;
        }
        newnode->val=head->val;
        newnode->next= nullptr;
        hash[head]=newnode;
        Node* newhead2=newhead;
        while(cur){
            newhead2->random= hash[cur->random];
            newhead2=newhead2->next;
            cur=cur->next;
        }

        return newhead;
    }
};
