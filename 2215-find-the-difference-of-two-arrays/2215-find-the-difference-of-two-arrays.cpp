class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<vector<int>> ans(2);
        
        int i = 0, j = 0;
        while(i < n && j < m) {
            
            if(nums1[i] == nums2[j]) {
                int x = nums1[i];
                
                while(i < n && nums1[i] == x) {
                    i++;
                }
                
                while(j < m && nums2[j] == x) {
                    j++;
                }
            }
            else if(nums1[i] < nums2[j]) {
                
                if(ans[0].empty() || ans[0].back() != nums1[i]) {
                    ans[0].push_back(nums1[i]);
                }
                i++;
            }
            else {
                if(ans[1].empty() || ans[1].back() != nums2[j]) {
                    ans[1].push_back(nums2[j]);
                }
                j++;
            }
        }
        
        while(i < n) {
            if(ans[0].empty() || ans[0].back() != nums1[i]) {
                ans[0].push_back(nums1[i]);
            }
            i++;
        }
        
        while(j < m) {
            if(ans[1].empty() || ans[1].back() != nums2[j]) {
                    ans[1].push_back(nums2[j]);
            }
            j++;
        }
        
        return ans;
        
        
        
    }
};