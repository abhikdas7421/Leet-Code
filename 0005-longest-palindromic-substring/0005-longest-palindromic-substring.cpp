class Solution {
public:
    string expandAlongIndex(string &s, int i, int j) {
        string ans = "";
        
        while(i >= 0 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
        }
        
        ans = s.substr(i+1, j-i-1);
        
        return ans;
    }
    
    string longestPalindrome(string s) {
        string ans = "";
        
        for(int i = 0; i < s.size(); i++) {
            string oddStr = expandAlongIndex(s, i, i);
            
            string evenStr = expandAlongIndex(s, i, i+1);
            
            if(ans.size() > oddStr.size() && ans.size() > evenStr.size()) {
                ans = ans;
            }
            else if(oddStr.size() > evenStr.size()) {
                ans = oddStr;
            }
            else {
                ans = evenStr;
            }
        }
        
        return ans;
    }
};