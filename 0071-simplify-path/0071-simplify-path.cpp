class Solution {
public:
    void buildAns(stack<string> &st, string &ans) {
        if(st.empty()) return;
        
        string minPath = st.top(); st.pop();
        buildAns(st, ans);
        ans += minPath;
    }
    

    string simplifyPath(string path) {
        int i = 0;
        int n = path.length();
        
        stack<string> st;
        while(i < n) {
            int start = i;
            int end = start+1;
            
            while(end < path.length() && path[end] != '/') {
                end++;
            }
            
            string minPath = path.substr(start, end-start);
            i = end;
            
            if(!st.empty() && minPath == "/..") {
                st.pop();
            }
            else if(minPath != "/." && minPath != "/" && minPath != "/..") {
                st.push(minPath);
            }
            
        }
        
        string ans = st.empty() ? "/": "";
        buildAns(st, ans);
        return ans;
        
    }
};