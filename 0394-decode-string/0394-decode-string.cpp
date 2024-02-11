class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        
        for(auto ch : s) {
            if(ch != ']') {
                string temp(1, ch);
                st.push(temp);
            }
            else {
                string temp = "";
                while(!st.empty() && st.top() != "[") {
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                
                string num = "";
                while( !st.empty() && isdigit(st.top()[0]) ) {
                    num += st.top();
                    st.pop();
                }
                
                reverse(num.begin(), num.end());
                int n = stoi(num);
                
                string temp2 = "";
                while(n--) {
                    temp2 += temp;
                }
                st.push(temp2);
            }
        }
        
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};