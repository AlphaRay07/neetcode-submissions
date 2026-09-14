class Solution:
    def rob(self, nums: List[int]) -> int:
        memo= [-1]*(len(nums)+1)
        x=[]
        def recur(n):
            if n<0 or n>=len(nums):
                return 0
            if n==len(nums)-1:
                return nums[n]
            if memo[n]!=-1:
                return memo[n]
            memo[n]=max(recur(n+1), nums[n] + recur(n+2))
            return memo[n]
        return recur(0)