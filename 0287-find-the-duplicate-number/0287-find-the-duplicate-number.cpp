class Solution {
public:
    // Approach:- 1 (Array)
    int findDuplicate(vector<int>& nums) {

        while (nums[0] != nums[nums[0]]) {
            swap(nums[0], nums[nums[0]]);
        }

        return nums[0];
    }
};