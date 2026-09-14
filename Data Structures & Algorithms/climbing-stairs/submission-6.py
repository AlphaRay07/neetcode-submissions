class Solution:
    def climbStairs(self, n: int) -> int:
        self.m=defaultdict(lambda: -1)
        # print(m)
        def f(n):
            if n<0:
                return 0
            if n==0:
                self.m[0]=1
                return 1
            if n==1:
                self.m[1]=1
                return 1
            if self.m[n-1]!=-1 and self.m[n-2]!=-1:
                return self.m[n-1]+self.m[n-2]

            self.m[n]= f(n-1) + f(n-2)
            return self.m[n]

        return f(n)