class Solution {
public:
    // Approach:- 1 (counting)
    /*void sortColors(vector<int>& nums) {
        int zeros = 0, ones = 0, twos= 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                zeros++;
            }
            else if(nums[i] == 1) {
                ones++;
            }
            else if(nums[i] == 2) {
                twos++;
            }
        }
        
        int i = 0;
        while(zeros--) {
            nums[i++] = 0;
        }
        
        while(ones--) {
            nums[i++] = 1;
        }
        
        while(twos--) {
            nums[i++] = 2;
        }
    }*/
    
    // Approach:- 2 (Dutch national flag algorithm)
    void sortColors(vector<int>& nums) { 
        int n = nums.size();
        
        int l = 0;
        int m = 0;
        int h = n-1;
        
        while(m <= h) {
            if(nums[m] == 0) {
                swap(nums[l], nums[m]);
                l++;
                m++;
            }
            else if(nums[m] == 1) {
                m++;
            }
            else {
                swap(nums[m], nums[h]);
                h--;
            }
        }
    }
};