from collections import defaultdict

class Solution:
    def longestPalindrome(self, s: str) -> str:
        res= ""
        resLen=0
        
        for i in range(len(s)):
            l=r=i
            while l<=r and l>=0 and r<len(s) and s[l]==s[r]:
                # print("entered")
                # print(s[l],s[r])
                if (r-l+1)>resLen:
                    res= s[l:r+1]
                    resLen= r-l+1
                    # print(res)
                l-=1
                r+=1

            l,r=i,i+1
            while l<=r and l>=0 and r<len(s) and s[l]==s[r]:
                # print("entered")
                # print(s[l],s[r])
                if (r-l+1)>resLen:
                    res= s[l:r+1]
                    resLen= r-l+1
                    # print(res)
                l-=1
                r+=1
        return res
        
        
        