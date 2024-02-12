class Solution {
public:
    // Approach 1:- Using Map | T.C -> O(n) | S.C-> O(n)
    /*int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        for(auto num : nums) {
            mp[num]++;
        }
        
        int ans = -1;
        for(auto it : mp) {
            if(it.second > nums.size()/2) {
                ans = it.first;
                break;
            }
        }
        
        return ans;
    }
    */
    
    // Approach 2:- By sorting | T.C -> O(nlogn) | S.C -> O(1)
    /*int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size()/2;
        
        return nums[n];
    }
    */
    
    // Approach 3:- Moore's Voting Algorithm | T.C -> O(n) | S.C -> O(1)
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0; // random number
        
        for(auto num : nums) {
            
            if(count == 0) {
                candidate = num;
            }
            
            count += (candidate == num) ? 1 : -1;
            
        }
        
        return candidate;
    }
};


















