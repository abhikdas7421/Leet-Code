class Solution {
public:
    // Approach:- 1 (Two Pass Soln)
    /*int slidingWindowHelper(vector<int> &nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        
        int i = 0;
        int j = 0;
        int result = 0;
        
        while(j < n) {
            mp[nums[j]]++;
            
            while(i < j && mp.size() > k) {
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }
            
            if(mp.size() <= k) {
                result += (j-i+1);
            }
            
            j++;
        }
        
        return result;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int count1 = slidingWindowHelper(nums, k);
        int count2 = slidingWindowHelper(nums, k-1);
        
        int result = count1 - count2;
        
        return result;
    }*/
    
    // Approach:- 2 (One Pass Soln)
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        
        int i_chota = 0;
        int j = 0;
        int i_bada = 0;
        
        int result = 0;
        
        while(j < n) {
            mp[nums[j]]++;
            
            while(mp.size() > k) {
                mp[nums[i_chota]]--;
                if(mp[nums[i_chota]] == 0) {
                    mp.erase(nums[i_chota]);
                } 
                
                i_chota++;
                i_bada = i_chota;
            }
            
            while(mp[nums[i_chota]] > 1) {
                mp[nums[i_chota]]--;
                i_chota++;
            }
            
            if(mp.size() == k) {
                result += (1 + i_chota-i_bada);
            }
            
            j++;
        }
        
        return result;
    }
};