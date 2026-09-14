class Solution {
private: 
    unordered_map<int, vector<pair<int,int>>> edges;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(auto i: times){
            edges[i[0]].push_back({i[1],i[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> h;
        set<int> visited;
        h.push({0,k});
        int t=0;
        while(!h.empty()){
            auto curr= h.top();
            h.pop();
            int w1= curr.first; int n1= curr.second;
            if(visited.count(n1)) continue;
            visited.insert(n1);
            t=w1;
            if(edges[n1].size()){
                for(auto i: edges[n1]){
                    int w2= i.second; int n2= i.first;
                    if(!visited.count(n2)) h.push({w1+w2,n2});
                }
            }
        }
        for(auto c: visited){
            printf("%d\n",c);
        }
        return visited.size()==n ? t : -1;
    }
};
