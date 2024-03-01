class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans = "";
        sort(s.begin(), s.end(), greater<char>()); // O(nlogn);
        
        ans = s.substr(1, s.size());
        ans.push_back('1');
        return ans;
    }
};