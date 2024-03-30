class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        
        int count = 0;
        int currCount = 0;
        
        for(int &num : nums) {
            if(num == 0) {
                count = max(count, currCount);
                currCount = 0;
            }
            else {
                currCount++;
            }
        }
        
        count = max(count, currCount);
        
        return count;
    }
};