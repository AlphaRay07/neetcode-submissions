class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dic=defaultdict(list)
        for i in strs:
            li=[0]*26 
            for j in i:
                li[ord(j)-ord('a')]+=1
            dic[tuple(li)].append(i)
        # print(dic)
        return list(dic.values())