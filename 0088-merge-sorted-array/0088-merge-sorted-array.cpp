class Solution {
public:
    // Approach:- 1 | T.C:- O(max(n, m)) | S.C:- O(n+m)
    /*void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
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
    }*/
    
    // Approach:- 2
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        for(int i = m; i < n+m; i++) {
            nums1[i] = nums2[i-m];
        }
        
        sort(nums1.begin(), nums1.end());
    }
    
};