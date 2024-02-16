class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map <int, int> mp;
        for(int &x : arr) {
            mp[x]++;
        }
        
        vector<int> freq;
        for(auto &it : mp) {
            freq.push_back(it.second);
        }
        sort(freq.begin(), freq.end(), greater<int>());
        
        for(int i = 0; i < k; i++) {
            freq[freq.size()-1] -= 1;
            
            if(freq[freq.size()-1] == 0) {
                freq.pop_back();
            }
        }
        
        return freq.size();
    }
};