class Solution {
public:
    void buildAns(stack<string> &st, string &ans) {
        if(st.empty()) return;
        
        string minPath = st.top(); st.pop();
        buildAns(st, ans);
        ans += minPath;
    }
    
    string getMinPath(int i, string path) {
        string directory = "";
        directory += path[i];
        i++;
        while(i < path.length() && path[i] != '/') {
            directory += path[i];
            i++;
        }
        
        return directory;
    }

    string simplifyPath(string path) {
        int i = 0;
        int n = path.length();
        
        stack<string> st;
        while(i < n) {
            string minPath = getMinPath(i, path);
            
            if(!st.empty() && minPath == "/..") {
                st.pop();
            }
            else if(minPath != "/." && minPath != "/" && minPath != "/..") {
                st.push(minPath);
            }
            
            i += minPath.length();
        }
        
        string ans = st.empty() ? "/": "";
        buildAns(st, ans);
        return ans;
        
    }
};