class Solution:

    def encode(self, strs: List[str]) -> str:
        # if len(strs)==0:
        #     return strs.join()
        # else:
        encoded=""
        for i in strs:
            encoded+=f"{len(i)}#{i}"
        print(encoded)
        return encoded
    def decode(self, s: str) -> List[str]:
        li=[]
        j=0
        print(s)
        while j<len(s):
            print(j)
            k=j
            while s[k]!="#":
                k+=1
            length=int(s[j:k])
            li.append(s[k+1:k+1+length])
            print(li)
            j=k+length+1
            # else:  
            #     li.append("")
            #     j+=1
        print(li)
        return li
