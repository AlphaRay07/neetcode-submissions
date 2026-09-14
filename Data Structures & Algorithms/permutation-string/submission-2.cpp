#include <unordered_map>

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> hash;
        unordered_set<char> set1(s1.begin(),s1.end());
        bool curflag= false;
        bool flag=false;
        for(char c: s1){
            hash[c]+=1;
        }
        int p=0;
        for(int i=0;i<s2.length();i++){
            if(flag) break;
            if(hash[s2[i]]){
                if(curflag) flag=curflag;
                if(i+s1.length()-1<s2.length()){
                    unordered_map<char, int> hash2;
                    string str= s2.substr(i,s1.length());
                    printf("%s\n",str.c_str());
                    for( char c: str){
                        hash2[c]+=1;
                    }
                    for(int j=i;j<i+s1.length();j++){
                        curflag=true;
                        if(hash2[s2[j]]!=hash[s2[j]]){
                            printf("false %d\n",j);
                            i=j;
                            curflag=false;
                            break;
                        }
                    }
                }
            }
        }
        if(curflag) flag=curflag;
        return flag;
    }
};
