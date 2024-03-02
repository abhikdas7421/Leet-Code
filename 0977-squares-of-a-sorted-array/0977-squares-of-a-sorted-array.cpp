class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> result(n);
        
        int s = 0, e = n-1; // nums---> indices
        int i = n-1; // result ---> indices
        
        while(s <= e) {
            int a = nums[s]*nums[s];
            int b = nums[e]*nums[e];
            
            if(a < b) {
                result[i] = b;
                e--;
            }
            else {
                result[i] = a;
                s++;
            }
            
            i--;
        }
        
        return result;
    }
};