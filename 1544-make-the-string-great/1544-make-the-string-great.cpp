class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        stack<char> st;
        
        int i = 0;
        while(i < n) {

            if(!st.empty() && (st.top()+32 == s[i] || st.top()-32 == s[i])){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
            i++;
        }
        
        string str = "";
        while(!st.empty()){
            str.push_back(st.top());
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};