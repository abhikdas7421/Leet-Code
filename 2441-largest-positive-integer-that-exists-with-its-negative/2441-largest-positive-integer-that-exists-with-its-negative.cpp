class Solution {
public:
    // Approach:- 1 | T.C:- O(n) | S.C:- O(n)
    /*int findMaxK(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        
        int ans = -1;
        
        for(int i = 0; i < n; i++) {
            int x = nums[i];
            
            if(mp.find(-x) != mp.end()) {
                ans = max(ans, abs(x));
            }
        }
        
        return ans;
    }*/
    
    // Approach:- 2 | T.C:- O(nlog(n)) | S.C:- O(1)
    /*int findMaxK(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int i = 0, j = n-1;
        
        while(i < j) {
            if(-nums[i] == nums[j]) {
                return nums[j];
            }
            else if(abs(nums[i]) > nums[j]) {
                i++;
            }
            else {
                j--;
            }
        }
        
        return -1;
    }*/
    
    // Approach:- 3 | T.C:- O(n) | S.C:- O(1)
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> arr(2001, 0);
        
        int result = -1;
        
        for(int i = 0; i < n; i++) {
            int num = nums[i];
            
            int idx = -num+1000;
            if(arr[idx] == 1) {
                result = max(result, abs(num));
            }
            
            arr[num+1000] = 1;
        }
        
        return result;
    }
};