class Solution {
public:
    // Approach:- 1(two pointer) | T.C:- O(nlog(n))
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        
        int i = 0; 
        int j = 1;
        set<pair<int, int>> ans;
        
        while(j < nums.size()) {
            int diff = nums[j]-nums[i];
            
            if(diff == k) {
                ans.insert({nums[i], nums[j]});
                i++;
                j++;
            }
            else if(diff < k) {
                j++;
            }
            else {
                i++;
            }
            
            if(i == j) j++;
        }
        
        for(auto &it:ans) {
            cout << it.first << " " << it.second << endl;
        }
        
        return ans.size();
    }
};