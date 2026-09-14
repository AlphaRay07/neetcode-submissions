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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next) return nullptr;
        int count=1;
        ListNode* cur=head;
        ListNode* slow=head;
        ListNode* slowprev=nullptr;
        while(cur->next){
            cur=cur->next;
            count++;
        }
        if(count==n){
            head=head->next;
            return head;
        }
        int index=0;
        while(index!=count-n){
            slowprev=slow;
            slow=slow->next;
            index++;
        }
        slowprev->next=slow->next;
        return head;
    }
};