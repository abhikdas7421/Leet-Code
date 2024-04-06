class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        
        int i = 0;
        while(i < s.size()) {
            if(s[i] == '(') {
                st.push(i);
                i++;
            }
            else if(s[i] == ')') {
                
                if(!st.empty()) {
                    st.pop();
                    i++;
                }
                else {
                    s.erase(i, 1);
                }
            }
            else {
                i++;
            }
        }
        
        while(!st.empty()) {
            int idx = st.top();
            st.pop();
            s.erase(idx, 1);
        }
        
        return s;
        
    }
};