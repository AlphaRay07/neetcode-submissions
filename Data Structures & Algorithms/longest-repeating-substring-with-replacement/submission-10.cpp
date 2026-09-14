class Solution {
public:
    int characterReplacement(string s, int k) {
        int count=0;
        int maxcount=0;
        unordered_set<char> ch(s.begin(),s.end());
        for(char c: ch){
            count=0;
            int sus=0;
            int p=0;
            for(int i=0;i<s.length();i++){
                if(s[i]!=c){
                    sus++;
                }
                while(sus>k){
                    if(s[p]!=c) sus--;
                    p++;
                }
                maxcount = max(maxcount, i - p + 1);
            }
            maxcount=max(maxcount,count);
        }
        return maxcount;
    }
};
