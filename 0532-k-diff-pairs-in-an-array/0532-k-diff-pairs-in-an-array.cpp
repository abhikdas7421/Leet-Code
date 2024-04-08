class Solution {
public:
    // Approach:- 1(two pointer) | T.C:- O(nlog(n)) | S.C:- O(n)
    /*int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        
        int i = 0; 
        int j = 1;
        set<pair<int, int>> ans;
        
        while(j < nums.size()) {
            int diff = nums[j]-nums[i];
            
            if(diff == k) {
                ans.insert({nums[i++], nums[j++]});
                // i++;
                // j++;
            }
            else if(diff < k) {
                j++;
            }
            else {
                i++;
            }
            
            if(i == j) j++;
        }
        
        return ans.size();
    }*/
    
    // Approach:- 2 (Using binary search) | T.C:- O(nlog(n)) | S.C:- O(n)
    bool binary_search(vector<int>& nums, int s, int e, int target) {
        
        while(s <= e) {
            int mid = s + (e-s)/2;
            
            if(nums[mid] == target) {
                return true;
            }
            else if(target < nums[mid]) {
                e = mid-1;
            }
            else {
                s = mid+1;
            }
        }
        
        return false;
    }
    
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        set<pair<int, int>> ans;
        
        for(int i = 0; i < n; i++) {
            int diff = k+nums[i];
            
            if(binary_search(nums, i+1, n-1, diff)) {
                ans.insert({nums[i], diff});
            }
            
        }
        
        return ans.size();
    }
    
};