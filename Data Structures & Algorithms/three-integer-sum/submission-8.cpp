class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        set<vector<int>> result;
        for(int i=0;i<nums.size()-1;i++){
            int l=i+1;
            int r=nums.size()-1;
            while(l<r){
                if((nums[i]+nums[l]+nums[r])>0) r--;
                else if((nums[i]+nums[l]+nums[r])<0) l++;
                else{
                    result.insert({nums[i],nums[l], nums[r]});
                    l++;
                    r--;
                }
            }
        }
        return vector<vector<int>>(result.begin(),result.end());
    }
};
