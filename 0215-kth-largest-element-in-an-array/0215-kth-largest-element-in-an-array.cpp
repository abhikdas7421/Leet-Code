class Solution {
public:
    // Approach 1:- Sort Decending order | T.C:- O(nlogn)
    /*int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k-1];
    }*/
    
    // Approach 2:- Sort Acending order | T.C:- O(nlogn)
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};