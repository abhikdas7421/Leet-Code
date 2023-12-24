class Solution {
public:
    void solve(vector<string> &ans, int open, int close, int n, string &str) {
        // base case
        if(open == 0 && close == 0) {
            ans.push_back(str);
            return;
        }
        
        // include opening parentheses
        if(open > 0) {
            str.push_back('(');
            solve(ans, open-1, close, n, str);
            str.pop_back();
        }
        
        
        // include closing parentheses
        if(close > open) {
            str.push_back(')');
            solve(ans, open, close-1, n, str);
            str.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open = n;
        int close = n;
        string str = "";
        
        solve(ans, open, close, n, str);
        return ans;
    }
};