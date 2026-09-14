class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        s=set()
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                if nums[i]+nums[j]==target:
                    s.add(i)
                    s.add(j)

        return list(s)