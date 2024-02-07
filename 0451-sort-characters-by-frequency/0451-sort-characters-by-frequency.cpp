class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char, int>> v(123);
        
        for(auto ch : s) {
            int freq = v[ch].second;
            v[ch] = {ch, freq+1};
        }
        
        auto cmp = [&](pair<char, int> &p1, pair<char, int> &p2) {
            return p1.second > p2.second;
        };
        
        sort(v.begin(), v.end(), cmp);
        
        string ans = "";
        for(int i = 0; i < 123; i++) {
            if(v[i].second == 0) {
                break;
            }
            
            char ch = v[i].first;
            int freq = v[i].second;
            string temp = string(freq, ch);
            
            ans += temp;
        }
        
        return ans;
            
            
    }
};