from collections import deque 
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        q=deque()
        maxarea=0
        currarea=0
        rlen= len(grid)
        clen= len(grid[0])
        def bfs(r,c):
            nonlocal maxarea
            currarea=1
            q.append((r,c))
            while q:
                (r1,c1)= q.popleft()
                print(currarea)
                if (r1+1)<rlen and grid[r1+1][c1] == 1:
                    currarea+=1
                    grid[r1+1][c1]=0
                    q.append((r1+1,c1))
                if (c1+1)<clen and grid[r1][c1+1] == 1:
                    currarea+=1
                    grid[r1][c1+1]=0
                    q.append((r1,c1+1))
                if (c1-1)>=0 and grid[r1][c1-1] == 1:
                    currarea+=1
                    grid[r1][c1-1]=0
                    q.append((r1,c1-1))
                if (r1-1)>=0 and grid[r1-1][c1] == 1:
                    currarea+=1
                    grid[r1-1][c1]=0
                    q.append((r1-1,c1))
            if currarea > maxarea:
                maxarea= currarea

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]==1:
                    grid[i][j]=0
                    bfs(i,j)
        return maxarea