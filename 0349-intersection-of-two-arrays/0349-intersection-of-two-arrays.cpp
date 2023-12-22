class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i = 0, j = 0;
        int n = nums1.size();
        int m = nums2.size();
        int lastEle = -1;
        while(i < n && j < m) {
            
            if(nums1[i] == nums2[j]) {
                if(lastEle != nums1[i]) {
                    ans.push_back(nums1[i]);
                    lastEle = nums1[i];
                }
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j]) {
                i++;
            }
            else if(nums1[i] > nums2[j]) {
                j++;
            }
        }
       
        
        return ans;
        
        
    }
};