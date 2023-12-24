class Solution {
public:
    void solve(string &digits, int index, vector<string> &ans, string output, vector<string> &mapping) {
        // base case 
        if(index >= digits.size()) {
            ans.push_back(output);
            return;
        }
        
        string value = mapping[digits[index] - '0'];
        
        for(int i = 0; i < value.size(); i++) {
            solve(digits, index+1, ans, output+value[i], mapping);
            
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        
        if(digits.size() == 0) {
            return ans;
        }
        
        string output = "";
        vector<string> mapping(10);
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";
        
        int index = 0;
        
        solve(digits, index, ans, output, mapping);
        return ans;
    }
};