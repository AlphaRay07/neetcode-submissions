class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums)==1: return 1
        if len(nums)==0: return 0
        s=set(nums)
        l=sorted(list(s))
        print(l)
        if len(l)==1: return 1
        sens=[]
        n=1
        for i in range(1,len(l)):
            # print(l[i+1],l[i])
            # print(n)
            if l[i]-l[i-1]==1: n+=1
            else:
                sens.append(n)
                n=1

        sens.append(n)
        return max(sens)