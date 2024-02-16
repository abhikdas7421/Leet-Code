class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map <int, int> mp;
        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]]++;
        }
        
        vector<int> ans;
        for(auto it : mp) {
            ans.push_back(it.second);
        }
        sort(ans.begin(), ans.end(), greater<int>());
        
        for(int i = 0; i < k; i++) {
            ans[ans.size()-1] -= 1;
            
            if(ans[ans.size()-1] == 0) {
                ans.pop_back();
            }
        }
        
        return ans.size();
    }
};