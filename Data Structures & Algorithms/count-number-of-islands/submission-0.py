from collections import deque

class Solution:

    def numIslands(self, grid: List[List[str]]) -> int:
        queue = deque()
        num=0
        rlen= len(grid)
        clen= len(grid[0])
        def bfs(r,c):
            queue.append((r,c))
            while queue:
                t=queue.popleft()
                r1=t[0]
                c1=t[1]
                if (r1+1)<rlen and grid[r1+1][c1] == "1":
                    grid[r1+1][c1]="0"
                    queue.append((r1+1,c1))
                if (c1+1)<clen and grid[r1][c1+1] == "1":
                    grid[r1][c1+1]="0"
                    queue.append((r1,c1+1))
                if (c1-1)>=0 and grid[r1][c1-1] == "1":
                    grid[r1][c1-1]="0"
                    queue.append((r1,c1-1))
                if (r1-1)>=0 and grid[r1-1][c1] == "1":
                    grid[r1-1][c1]="0"
                    queue.append((r1-1,c1))

        for i in range(rlen):
            for j in range(clen):
                if grid[i][j]=="1":
                    num+=1
                    print(i,j)
                    grid[i][j]="0"
                    bfs(i,j)
        return num