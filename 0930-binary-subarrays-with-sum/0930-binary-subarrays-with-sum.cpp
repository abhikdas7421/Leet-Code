class Solution {
public:
    // Approach:- 1 (Same as LC - 560 Subarray Sum Equals K)
    /*int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> mp;
        
        int result = 0;
        int currSum = 0;
        
        mp[0] = 1;
        
        for(int &num : nums) {
            currSum += num;
            
            if(mp.find(currSum-goal) != mp.end()) {
                result += mp[currSum-goal];
            }
            
            mp[currSum]++;
        }
        
        return result;
    }*/
    
    // Approach:- 2 (Sliding window)
    /*int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        
        int i = 0;
        int j = 0;
        
        int window_sum = 0;
        int count_zeros = 0;
        int result = 0;
        
        while(j < n) {
            window_sum += nums[j];
            
            while(i < j && (nums[i] == 0 || window_sum > goal)) {
                
                if(nums[i] == 0) {
                    count_zeros++;
                }
                else {
                    count_zeros = 0;
                }
                
                window_sum -= nums[i];
                i++;
            }
            
            if(window_sum == goal) {
                result += 1+count_zeros;
            }
            
            j++;
        }
        
        return result;
    }*/
    
    // Approach:- 3 (Sliding Window 2)
    int slidingWindow(vector<int>& nums, int goal) {
        int n = nums.size();
        int window_sum = 0;
        
        int i = 0;
        int j = 0;
        int result = 0;
        
        while(j < n) {
            window_sum += nums[j];
            
            while(i < j && window_sum > goal) {
                window_sum -= nums[i];
                i++;
            }
            
            if(window_sum <= goal) {
                result += (j-i+1);
            }
            j++;
        }
        
        return result;
        
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count1 = slidingWindow(nums, goal);
        int count2 = slidingWindow(nums, goal-1);
        
        int result = count1-count2;
        return result;
    }
};