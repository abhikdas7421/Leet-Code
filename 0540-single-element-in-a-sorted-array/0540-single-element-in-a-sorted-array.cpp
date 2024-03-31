class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        int s = 0;
        int e = n-1;
        
        while(s < e) {
            int mid = s + (e-s)/2;
            cout << mid << endl;
            
            if(mid%2 == 0) { // mid even
                if(nums[mid] == nums[mid+1]) {
                    s = mid+2;
                }
                else {
                    e = mid;
                }
            }
            else { // mid odd
                if(nums[mid] == nums[mid+1]) {
                    e = mid-1;
                }
                else {
                    s = mid+1;
                }
            }
        }
        
        return nums[s];
    }
};