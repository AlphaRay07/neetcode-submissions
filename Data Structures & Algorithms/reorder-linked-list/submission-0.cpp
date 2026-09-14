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
    void reorderList(ListNode* head) {
        ListNode* r= head;
        ListNode* fast=head;
        ListNode* slow=head;
        int count=0;
        while(r){
            r=r->next;
            count++;
        }
        int i=count/2;
        count=0;
        r=head;
        while(r && count!=i){
            r=r->next; count++;
        } 
        fast=r;
        ListNode* cur=fast;
        ListNode* prev=nullptr;
        ListNode* nex= fast;

        while(cur){
            nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }

        // while(cur){
        //     cur->next=prev;
        //     prev=cur;
        //     cur=nex;
        //     nex=nex->next;
        // }

        nex=slow->next;
        fast=prev;
        ListNode* dummy=nullptr;
        while(i && fast!=nex){
            slow->next=fast;
            dummy=fast->next;
            fast->next=nex;
            fast=dummy;
            slow=nex;
            nex=nex->next;
            i--;
        }
    }
};
