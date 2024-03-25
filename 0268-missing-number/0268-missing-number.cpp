class Solution {
public:
    // Approach:- 1(Math)
    /*int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int totalSum = (n * (n+1))/2;

        int arraySum = 0;
        for(int &num : nums) {
            arraySum += num;
        }

        int missingNum = totalSum-arraySum;
        return missingNum;
    }*/

    // Approach:- 2(bit manupulation)
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        for(int &num : nums) {
            ans ^= num;
        }

        for(int i = 0; i <= nums.size(); i++) {
            ans ^= i;
        }

        return ans;
    }
};




















