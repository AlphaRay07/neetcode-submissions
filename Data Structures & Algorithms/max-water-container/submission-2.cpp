class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res=0;
        // for(int i=0;i<heights.size();i++){
        //     for(int j=i+1;j<heights.size();j++){
        //         int s=min(heights[i],heights[j]);
        //         int w= j-i;
        //         res= max(res,w*s);
        //     }
        // }

        int l= 0;
        int r= heights.size()-1;
        while(l<r){
            res= max(min(heights[l],heights[r])*(r-l),res);
            if(heights[l]<heights[r]){
                l++;
            }else r--;
        }
        return res;
    }
};
