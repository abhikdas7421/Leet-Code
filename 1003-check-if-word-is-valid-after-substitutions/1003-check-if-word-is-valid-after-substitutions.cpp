class Solution {
public:
    bool isValid(string s) {
        if(s[0] != 'a') return false;
        
        stack<char> st;
        for(auto ch : s) {
            
            if(ch == 'a') {
                st.push(ch);
            }
            else if(ch == 'b') {
                if(!st.empty() && st.top() == 'a') {
                    st.push(ch);
                }
                else {
                    return false;
                }
            }
            else if(ch == 'c') {
                
               if(!st.empty() && st.top() == 'b') {
                   st.pop();
                }
                else {
                    return false;
                }
                
                if(!st.empty() && st.top() == 'a') {
                    st.pop();
                }
                else {
                    return false;
                }
                
            }
        }
        
        return st.empty();
    }
};