class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> result(n);
        
        int s = 0, e = n-1;
        int i = n-1;
        
        while(s <= e) {
            if(abs(nums[s]) < abs(nums[e])) {
                result[i] = nums[e]*nums[e];
                e--;
            }
            else {
                result[i] = nums[s]*nums[s];
                s++;
            }
            
            i--;
        }
        
        return result;
    }
};