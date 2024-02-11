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
                string stringToRepeat = "";
                while(!st.empty() && st.top() != "[") {
                    stringToRepeat += st.top();
                    st.pop();
                }
                st.pop();
                
                string numericTimes = "";
                while( !st.empty() && isdigit(st.top()[0]) ) {
                    numericTimes += st.top();
                    st.pop();
                }
                
                reverse(numericTimes.begin(), numericTimes.end());
                int n = stoi(numericTimes);
                
                string currDecode = "";
                while(n--) {
                    currDecode += stringToRepeat;
                }
                st.push(currDecode);
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