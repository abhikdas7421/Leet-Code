class Solution {
public:
    int longestValidParentheses(string s) {
        int longLen = 0;
        
        stack<int> st;
        st.push(-1);
        
        for(int i = 0; i < s.size(); i++) {
            
            if(s[i] == '(') {
                st.push(i);
            }
            else {
                st.pop();
                
                if(!st.empty()) {
                    int currLen = i - st.top();
                    longLen = max(longLen, currLen);
                }
                else {
                    st.push(i);
                }
            }
            
        }
        
        return longLen;
    }
};