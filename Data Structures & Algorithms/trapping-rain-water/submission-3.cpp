class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0) return 0;
        int l=0;
        if(height[l]==0) l++;
        int r=height.size()-1;
        if(height[r]==0) r--;
        int res=0;
        int lmax=l;
        int rmax=r;
        while(l<r){
            if(height[l]<height[lmax]){
                res+=height[lmax]-height[l];
            }else lmax=l;
            if(height[r]<height[rmax]){
                res+=height[rmax]-height[r];
            }else rmax=r;
            if(height[l]>height[r]) r--;
            else l++;
        }
        return res;
    }
};
