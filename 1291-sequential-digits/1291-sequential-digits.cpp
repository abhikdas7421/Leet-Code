class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> ans;
        for(int len = 2; len <= s.length(); len++) {
            for(int i = 0; i <= s.length()-len; i++) {
                string temp = s.substr(i, len);
                int pass = stoi(temp);
                
                if(low <= pass && pass <= high) {
                    ans.push_back(pass);
                }
            }
        }
        
        return ans;
    }
};