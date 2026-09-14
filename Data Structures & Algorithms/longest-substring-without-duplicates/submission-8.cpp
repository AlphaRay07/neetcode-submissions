#include <unordered_map>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.length()) return 0;
        unordered_map<char,int> hash;
        // vector<int> store;
        int count=0;
        int maxcount=0;
        int p=0;
        for(int i=0;i<s.length();i++){
            hash[s[i]]+=1;
            if(hash[s[i]]>1){
                while(hash[s[i]]>1){
                    hash[s[p]]--;
                    p++;
                }
                maxcount= max(count,maxcount);
                count=i-p+1;
            }
            else count++;
        }
        maxcount= max(count,maxcount);
        return maxcount;
    }
};
