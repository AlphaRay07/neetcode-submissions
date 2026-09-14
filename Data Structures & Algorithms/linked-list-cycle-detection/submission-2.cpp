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
    bool hasCycle(ListNode* head) {
        if(!head) return false;
        bool b=false;
        unordered_map<int,int> hash;
        while(head){
            if( head->next && hash[head->val] && hash[head->next->val]){
                b=true;
                break;
            }
            hash[head->val]++;
            head=head->next;
        }
        return b;
    }
};
