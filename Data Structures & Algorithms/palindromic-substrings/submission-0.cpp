class Solution {
public:
    int countSubstrings(string s) {
        int n=0;
        for(int i=0;i<s.length();i++){
            int l=i;
            int r=i;
            while(l<=r && l>=0 && r<s.length() && s[l]==s[r]){
                n++;
                l--;
                r++;
            }
            l=i;
            r=i+1;
            while(l<=r && l>=0 && r<s.length() && s[l]==s[r]){
                n++;
                l--;
                r++;
            }
            printf("%d\n",n);
        }
        return n;
    }
};
