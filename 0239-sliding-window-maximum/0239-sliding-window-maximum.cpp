class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        
        for(int i = 0; i < k; i++) {
            
            while(!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        
        ans.push_back(nums[dq.front()]);
        
        int i = 0;
        int j = k;
        
        while(j < nums.size()) {
            
            while(!dq.empty() && dq.front() <= i) {
                dq.pop_front();
            }
            
            while(!dq.empty() && nums[j] >= nums[dq.back()]) {
                dq.pop_back();
            }
            
            dq.push_back(j);
            
            ans.push_back(nums[dq.front()]);
            
            i++;
            j++;            
        }
        
        return ans;
    }
};