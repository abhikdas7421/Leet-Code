class Solution {
public:
    bool isUnique(string str1, string str2) {
        vector<int> freq(26, 0);
        
        for(auto ch : str1) {
            if(freq[ch-'a']) {
                return false;
            }
            freq[ch-'a']++;
        }
        
        for(auto ch : str2) {
            if(freq[ch-'a']) {
                return false;
            }
            freq[ch-'a']++;
        }
        
        return true;
    }
    unordered_map<string, int> mp;
    int solve(vector<string> &arr, int i, string temp) {
        
        if(i >= arr.size()) {
            mp[temp] = temp.length();
            return mp[temp];
        }
        
        if(mp.find(temp) != mp.end()) {
            return mp[temp];
        }
        
        int include = 0;
        int exclude = 0;
        
        exclude = solve(arr, i+1, temp);
        if(isUnique(temp, arr[i])) {
            include = solve(arr, i+1, temp+arr[i]);
        }
        
        mp[temp] = max(include, exclude);
        return mp[temp];
    }
    
    int maxLength(vector<string>& arr) {
        string temp = "";
        mp.clear();
        int ans = solve(arr, 0, temp);
        return ans;
    }
};