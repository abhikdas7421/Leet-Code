class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> pre(n, 0);
        vector<int> post(n, 0);
        
        for(int i = 1; i < n; i++) {
            pre[i] = pre[i-1] + nums[i-1];
        }
        
        for(int i = n-2; i >= 0; i--) {
            post[i] = post[i+1] + nums[i+1];
        }
        
        for(int i = 0; i < n; i++) {
            if(pre[i] == post[i])
                return i;
        }
        
        return -1;
    }
};