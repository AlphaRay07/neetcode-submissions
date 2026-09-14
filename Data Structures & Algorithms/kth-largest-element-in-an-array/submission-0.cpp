class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> h;
        int c=0;
        for(int i: nums) h.push(i);
        while(c!=k-1){
            h.pop();
            c++;
        }
        return h.top();
    }
};
