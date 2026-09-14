class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        dic=defaultdict(int)
        for i in nums:
            dic[i]+=1
        print(dic)
        values=[[] for i in range(len(nums))]
        print(values)
        res=[]
        for j in dic:
            print(j)
            values[dic[j]-1].append(j)
        x=len(values)-1
        print(values)
        while k and x>=0:
            if len(values[x]):
                res+=values[x]
                k-=len(values[x])
            x-=1
        return res