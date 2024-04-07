class Solution {
public:
    int dp[101][101];
    bool helper(string &s, int idx, int open) {
        if(idx >= s.length()) {
            return open == 0;
        }
        
        if(dp[idx][open] != -1) {
            return dp[idx][open] == 1 ? true : false;
        }
        
        bool isValid = false;
        
        if(s[idx] == '(') {
            isValid |= helper(s, idx+1, open+1);
        }
        else if(s[idx] == ')' && open > 0) {
            isValid |= helper(s, idx+1, open-1);
        }
        else if(s[idx] == '*'){
            // * -> as empty string
            isValid |= helper(s, idx+1, open);
            
            // * -> as open parenthesis '('
            isValid |= helper(s, idx+1, open+1);
            
            // * -> as close parenthesis ')'
            if(open > 0) {
                isValid |= helper(s, idx+1, open-1);
            }
            
        }
        return dp[idx][open] = isValid;
    }
    
    bool checkValidString(string s) {
        memset(dp, -1, sizeof(dp));
        return helper(s, 0, 0);
    }
};