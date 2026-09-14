class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> h;
        unordered_map<int,int> hash;
        for(int i=0;i<stones.size();i++){
            h.push(stones[i]);
            hash[stones[i]]=i;
        }
        int x; int y;
        while(h.size()>1){
            x= h.top();
            h.pop();
            y= h.top();
            h.pop();
            if(x==y) continue;
            else if(x<y) h.push(y-x);
            else h.push(x-y);
        }
        if(!h.size()) return 0;
        return h.top();
    }
};
