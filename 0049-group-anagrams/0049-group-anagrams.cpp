class Solution {
public:
    vector<int> hash(string s) {
        vector<int> hash(26, 0);
        
        for(int i = 0; i < s.size(); i++) {
            hash[s[i]-'a']++;
        }
        
        return hash;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        
        for(auto str:strs) {
            mp[hash(str)].push_back(str);
        }
        
        vector<vector<string>> ans;
        
        for(auto it = mp.begin(); it != mp.end(); it++) {
            ans.push_back(it->second);
        }
        
        return ans;
    }
};