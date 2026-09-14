class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> hash;
        int val=0;
        for(int i: nums){
            if(hash[i]){ val=i;break;}
            hash[i]++;
        }
        return val;
    }
};
