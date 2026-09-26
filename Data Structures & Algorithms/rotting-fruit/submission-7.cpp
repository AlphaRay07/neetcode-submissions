class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int r=0;
        int ones=0;
        int count=0;
        queue<vector<int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) ones++;
            }
        }
        printf("%d\n",ones);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        while(ones>0 && !q.empty()){
            int s=q.size();
            for(int k=0;k<s;k++){
                vector<int> c= q.front();
                q.pop();
                int x=c[0]; int y=c[1];
                if(x-1>=0 && grid[x-1][y]==1){ q.push({x-1,y}); grid[x-1][y]=0; ones--;}
                if(x+1<grid.size() && grid[x+1][y]==1){ q.push({x+1,y}); grid[x+1][y]=0; ones--;}
                if(y-1>=0 && grid[x][y-1]==1){q.push({x,y-1}); grid[x][y-1]=0; ones--;}
                if(y+1<grid[0].size() && grid[x][y+1]==1){ q.push({x,y+1}); grid[x][y+1]=0; ones--;}
            }
            if(!q.empty()){ r++;printf("%d\n",r);}
        }
        printf("%d %d\n",count,ones);
        return ones == 0 ? r : -1;
    }
};
