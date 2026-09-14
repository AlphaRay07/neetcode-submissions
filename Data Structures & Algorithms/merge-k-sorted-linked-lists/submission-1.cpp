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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()<1) return nullptr;
        if(lists.size()==1) return lists[0];
        struct Compare {
            bool operator()(ListNode* a, ListNode* b) {
                return a->val > b->val;
            }
        };
        priority_queue<ListNode*,vector<ListNode*>, Compare> minHeap;
        ListNode* s= new ListNode();
        ListNode* head=s;
        for(auto p: lists){
            while(p){
                minHeap.push(p);
                p=p->next;
            }
        }
        while(!minHeap.empty()){
            s->val= (minHeap.top())->val;
            minHeap.pop();
            if(!minHeap.empty()){s->next=new ListNode();
            s=s->next;}
        }

        return head;
    }
};
