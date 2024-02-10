class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        
        // process first k window
        for(int i = 0; i < k; i++) {
            
            // Step 1:-  remove smaller element than curr element
            while(!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            
            // Step 2:- push_back curr element
            dq.push_back(i);
        }
        
        // Step 3:- store answer for first window
        ans.push_back(nums[dq.front()]);
        
        // Process remaining windows
        for(int i = k; i < nums.size(); i++) {
            
            // Step 1:- remove outof bound element from dq
            if(!dq.empty() && i-dq.front() >= k) {
                dq.pop_front();
            }
            
            // Step 2:- remove smaller element than curr element
            while(!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            
            // Step 3:- push_back curr element
            dq.push_back(i);
            
            // Step 4:- stroe answer for current window
            ans.push_back(nums[dq.front()]);
        }
        
        return ans;
    }
};