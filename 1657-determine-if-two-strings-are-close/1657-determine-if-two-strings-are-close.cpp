class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        
        int n = word1.size();
        
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        
        for(auto ch : word1) {
            mp1[ch]++;
        }
        for(auto ch : word2) {
            mp2[ch]++;
        }
        
        for(int i = 0; i < n; i++) {
            char ch1 = word1[i];
            char ch2 = word2[i];
            
            if(mp1.find(ch2) == mp1.end() || mp2.find(ch1) == mp2.end()) {
                return false;
            }
        }
        
        vector<int> v1;
        vector<int> v2;
        
        for(auto it : mp1) {
            v1.push_back(it.second);
        }
        
        for(auto it : mp2) {
            v2.push_back(it.second);
        }
        
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        return v1 == v2;
        
    }
};