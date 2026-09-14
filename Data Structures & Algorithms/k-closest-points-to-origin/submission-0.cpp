#include <cmath>

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float,vector<int>>> h;
        // unordered_map<float,vector<int>> hash;
        vector<vector<int>> r;
        for(auto p: points){
            int x=p[0];
            int y=p[1];
            float sq=sqrt(pow(x,2)+pow(y,2));
            // hash[sq]={x,y};
            // printf("%d %d\n",hash[sq][0],hash[sq][1]);
            h.push({sq,{x,y}});
        }
        int c=0;
        while(c!=(points.size()-k)){
            h.pop();
            c++;
        }
        while(!h.empty()){
            r.push_back(h.top().second);
            // printf("%d %d\n",hash[h.top()][0],hash[h.top()][1]);

            h.pop();
        }

        return r;
    }
};
