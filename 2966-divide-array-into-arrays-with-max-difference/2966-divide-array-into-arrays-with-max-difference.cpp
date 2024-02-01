class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        int i = 0;
        while(i < nums.size()) {
            vector<int> v;
            
            int j = 0;
            int firstEle = nums[i+j];
            while(j < 3) {
                
                if(nums[i+j]-firstEle <= k) {
                   v.push_back(nums[i+j]);
                    j++; 
                }
                else {
                    ans.clear();
                    return ans;
                }
                
            }
            i = i+j;
            ans.push_back(v);
        }
        return ans;   
    }
};