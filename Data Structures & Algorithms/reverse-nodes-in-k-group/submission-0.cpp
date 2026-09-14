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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* res=head;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prevhead= nullptr;
        // vector<ListNode*> l;
        while(fast){
            int count=1;
            while(count!=k && fast){
                fast=fast->next;
                count++;
            }
            if(count<k || !fast){prevhead->next=slow; break;}
            fast=fast->next;
            ListNode* prev=nullptr;
            ListNode* cur=slow;
            ListNode* nex= slow->next;
            while(cur!=fast){
                cur->next=prev;
                prev=cur;
                cur=nex;
                nex=nex->next;
            }
            if(prevhead) {prevhead->next=prev;}
            prevhead=slow;
            if(slow==head) res=prev;
            printf("%d\n",slow->val);
            // l.emplace_back(res);
            slow=fast;
        }

        return res;
    }
};
