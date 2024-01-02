class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> hash(n+1);
        
        for(int i = 0; i < nums.size(); ++i) {
            hash[nums[i]]++;
        }
        
        vector<int> row;
        bool flag = true;
        while(flag) {
            
            flag = false;
            for(int i = 1; i < hash.size(); ++i) {
                if(hash[i] >= 1) {
                    flag = true;
                    row.push_back(i);
                    --hash[i];
                }
            }
            
            
            if(row.size() > 0) {
                ans.push_back(row);
            }
            
            row.clear();
            
        }
        
        return ans;
        
        
    }
};