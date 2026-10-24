class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<vector<int>> q;
        vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O'){
                board[i][0]='S';
                q.push({i,0});
            }
            if(board[i][board[0].size()-1]=='O'){
                board[i][board[0].size()-1]='S';
                q.push({i,static_cast<int>(board[0].size()-1)});
            }
        }
        for(int i=0;i<board[0].size();i++){
            if(board[0][i]=='O'){
                board[0][i]='S';
                q.push({0,i});
            }
            if(board[board.size()-1][i]=='O'){
                board[board.size()-1][i]='S';
                q.push({static_cast<int>(board.size()-1),i});
            }
        }

        while(!q.empty()){
            auto x=q.front();
            q.pop();
            int s=q.size();
            for(auto d : dir) {
                int r = d[0];
                int c = d[1];
                if(x[0]+r>=0 && 
                x[0]+r<board.size() && x[1]+c>=0
                && x[1]+c<board[0].size()){
                    if(board[x[0]+r][x[1]+c]=='O'){
                        board[x[0]+r][x[1]+c]='S';
                        q.push({x[0]+r,x[1]+c});
                    }
                } 
            }
        }

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O') board[i][j]='X';
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='S') board[i][j]='O';
            }
        }
    }
};
