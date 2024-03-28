class Solution {
public:
    // Approach:- 1 | T.C:- O(log n) | S.C:- O(1)
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        
        while(start <= end) {
            int mid = start + (end-start)/2; // calculate mid in every iteration
            
            if(nums[mid] == target) {
                return mid; // target found
            }
            else if(target < nums[mid]) {
                end = mid-1; // search in left
            }
            else if(target > nums[mid]) {
                start = mid+1; // search in right
            }
        }
        
        
        return -1; // target not found
        
    }
};