class Solution {
public:
    int characterReplacement(string s, int k) {
        int count=0;
        int maxcount=0;
        
        // unordered_map<char,int> hash;
        unordered_set<char> ch(s.begin(),s.end());
        for(char c: ch){
            count=0;
            int sus=0;
            int p=0;
            char primary=c;
            for(int i=0;i<s.length();i++){
                // if(s[i]!=primary){
                //     sus++;
                //     if(k==0){
                //         p=i+1;
                //         sus--;
                //     }
                //     while(k && sus>k){
                //         // i=++p;
                //         // count--;
                //         // p++;
                //         if (s[p++] != primary) sus--;
                //         printf("%d\n",count);
                //         maxcount=max(maxcount,count);
                //         count--;
                //         // primary=s[p];
                //     }
                // }
                // count++;
                if (s[i] != primary)
                    sus++;

                while (sus > k) {

                    if (s[p] != primary)
                        sus--;

                    p++;
                }

                maxcount = max(maxcount, i - p + 1);
                // hash[s[i]]+=1;
            }
            maxcount=max(maxcount,count);
        }
        return maxcount;
    }
};
