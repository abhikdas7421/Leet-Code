class Solution {
public:
    // Approach:- 1 (Sorting) | T.C:- O(nlogn)
    /*int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size()-1; i++) {
            if(nums[i] == nums[i+1]) {
                return nums[i];
            }
        }
        
        return -1;
    }*/
    
    // Approach:- 2 | T.C:- O(n)
    /*int findDuplicate(vector<int>& nums) {
        
        while(nums[0] != nums[nums[0]]) {
            swap(nums[0], nums[nums[0]]);
        }
        
        return nums[0];
    }*/

    // Approach:- 3 (Hair and Tortoise)
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        
        // Cycle detection
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        slow = 0;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};