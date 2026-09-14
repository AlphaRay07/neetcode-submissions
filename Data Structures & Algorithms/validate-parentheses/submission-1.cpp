#include <stack>

class Solution {
public:
    bool isValid(string s) {
        // unordered_map<char,int> hash;
        // hash['(']++;
        // hash['[']++;
        // hash['{']++;
        stack<char> st;
        int p=s.size()-1;
        // bool r=false;
        
        for(char c: s){
            if(c==')'){
                if(st.empty()) return false;
                if(st.top()=='(') st.pop();
                else return false;
            }else if(c==']'){
                if(st.empty()) return false;
                if(st.top()=='[') st.pop();
                else return false;
            }else if(c=='}'){
                if(st.empty()) return false;
                if(st.top()=='{') st.pop();
                else return false;
            }else st.push(c);
        }
        if(st.empty()) return true;
        else return false;
    }
};
