class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows=[[] for i in board]
        cols=[[] for j in board[0]]
        rowdict=defaultdict(lambda: defaultdict(int))
        coldict=defaultdict(lambda: defaultdict(int))
        blockdict=defaultdict(lambda: defaultdict(int))
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j].isalnum():
                    rowdict[i][board[i][j]]+=1
                    coldict[j][board[i][j]]+=1
                    if rowdict[i][board[i][j]]>1 or coldict[j][board[i][j]]>1: 
                        print("hi")
                        return False
                    x=i//3
                    y=j//3
                    blockdict[(x,y)][board[i][j]]+=1
                    if blockdict[(x,y)][board[i][j]]>1:
                        print(blockdict[(x,y)])
                        print(i,j,x,y)
                        return False
        print(rowdict)
        print(coldict)
        print(blockdict)
        return True
