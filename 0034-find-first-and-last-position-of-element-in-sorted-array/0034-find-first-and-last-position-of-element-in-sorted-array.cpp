class Solution {
public:
    int firstPosition(vector<int>& nums, int target) {
        int pos = -1, start = 0, end = nums.size()-1;
        
        while(start <= end) {
            int mid = start + (end-start)/2;
            
            if(nums[mid] == target) {
                pos = mid;
                end = mid-1;
            }
            else if(target < nums[mid]) {
                end = mid-1;
            }
            else if(target > nums[mid]) {
                start = mid+1;
            }
        }
        
        return pos;
    }
    
    int lastPosition(vector<int>& nums, int target) {
        int pos = -1, start = 0, end = nums.size()-1;
        
        while(start <= end) {
            int mid = start + (end-start)/2;
            
            if(nums[mid] == target) {
                pos = mid;
                start = mid+1;
            }
            else if(target < nums[mid]) {
                end = mid-1;
            }
            else if(target > nums[mid]) {
                start = mid+1;
            }
        }
        
        return pos;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstPos = firstPosition(nums, target);
        
        int lastPos = -1;
        if(firstPos != -1) {
            lastPos = lastPosition(nums, target);
        }
        
    
        return {firstPos, lastPos};
    }
};