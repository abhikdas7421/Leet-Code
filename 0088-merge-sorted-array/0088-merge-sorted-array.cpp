class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> mergedArr(n+m);
        
        int i = 0; // for nums1
        int j = 0; // for nums2
        int k = 0; // for mergedArr
        
        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                mergedArr[k] = nums1[i];
                i++;
            }
            else {
                mergedArr[k] = nums2[j];
                j++;
            }
            k++;
        }
        
        while(i < m) {
            mergedArr[k++] = nums1[i++];
        }
        
        while(j < n) {
            mergedArr[k++] = nums2[j++];
        }
        
        i = 0; k = 0;
        
        while(k < n+m) {
            nums1[k] = mergedArr[k];
            k++;
        }
        
    }
};