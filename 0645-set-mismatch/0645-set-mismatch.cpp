class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> hash(nums.size()+1, 0);
        vector<int> ans(2);
        for(int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }
        
        for(int i = 1; i < hash.size(); i++) {
            if(hash[i] > 1) {
                ans[0] = i;
            }
            else if(hash[i] == 0) {
                ans[1] = i;
            }
        }
        
        return ans;
    }
};