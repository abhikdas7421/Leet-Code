class Solution {
public:
    static bool cmp(int a, int b) {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        
        string ans = "";
        
        if(nums[0] == 0) {
            return "0";
        }
        
        for(int &num : nums) {
            ans += to_string(num);
        }
        
        return ans;
    }
};