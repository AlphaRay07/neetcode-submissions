class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        if len(cost)==0:
            return
        self.d= len(cost)
        memo=defaultdict(lambda: -1)
        def recur(i):
            if i>=self.d:
                return 0
            if memo[i]!=-1:
                return memo[i]
            memo[i]=cost[i] + min(recur(i+2),recur(i+1))
            return memo[i]
        return min(recur(0), recur(1))