class Solution {
public:
    // Approach:- 1 | T.C:- O(m + n) | S.C:- O(m + n)
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
    
    // Approach:- 2 | T.C:- O((n+m)log(n+m)) | S.C:- O(1)
    /*void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        for(int i = m; i < n+m; i++) {
            nums1[i] = nums2[i-m];
        }
        
        sort(nums1.begin(), nums1.end());
    }*/
    
    // Approach:- 3 | T.C:- O(m + n) | S.C:- O(1)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = (n+m)-1;
        
        while(i >= 0 && j >= 0) {
            
            if(nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            }
            else {
                nums1[k--] = nums2[j--];
            }
        }
        
        while(j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
    
};