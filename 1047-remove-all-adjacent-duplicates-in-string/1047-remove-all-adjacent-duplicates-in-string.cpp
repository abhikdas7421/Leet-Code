class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        int i = 0;
        
        while(i < s.length()) {
            int lastIndex = ans.length()-1;
            
            if(lastIndex >= 0 && s[i] == ans[lastIndex]) {
                ans.pop_back();
            }
            else {
                ans.push_back(s[i]);
            }
            i++;
        }
        
        return ans;
        
    }
};