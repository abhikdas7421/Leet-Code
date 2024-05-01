class Solution {
public:
    int partition_algo(vector<int>& nums, int l, int r) {
        int pivot = nums[l];
        int i = l+1;
        int j = r;
        
        while(i <= j) {
            
            if(pivot > nums[i] && pivot < nums[j]) swap(nums[i++], nums[j--]);
                
            if(nums[i] >= pivot) i++;
            
            if(nums[j] <= pivot) j--;
            
        }
        
        swap(nums[l], nums[j]);
        return j;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        
        int l = 0;
        int r = n-1;
        
        while(true) {
            int pivot_idx = partition_algo(nums, l, r);
            
            if(pivot_idx == k-1) break;
            else if(pivot_idx > k-1) r = pivot_idx-1;
            else l = pivot_idx+1;
        }
        
        return nums[k-1];
    }
};