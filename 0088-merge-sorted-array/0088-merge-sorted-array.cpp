class Solution {
public:
    // Approach:- 1
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> mergedArray;
        
        int i = 0, j = 0;
        
        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                mergedArray.push_back(nums1[i]);
                i++;
            }
            else {
                mergedArray.push_back(nums2[j]);
                j++;
            }
        }
        
        while(i < m) {
            mergedArray.push_back(nums1[i]);
            i++;
        }
        
        while(j < n) {
            mergedArray.push_back(nums2[j]);
            j++;
        }
        
        nums1 = mergedArray;
    }
};