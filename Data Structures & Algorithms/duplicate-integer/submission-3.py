class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        dic=dict()
        for i in nums:
            dic[i]=0
        for i in nums:
            dic[i]+=1
            if dic[i]>1: return True
        return False