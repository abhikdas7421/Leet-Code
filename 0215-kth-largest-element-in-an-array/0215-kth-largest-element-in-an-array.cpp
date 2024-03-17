class Solution {
public:
    // Approach 1:- Sort Decending order | T.C:- O(nlogn)
    /*int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k-1];
    }*/
    
    // Approach 2:- Sort Acending order | T.C:- O(nlogn)
    /*int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }*/
    
    // Approach 3:- Using Min Heap
    /*int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq; // default max heap
        
        for(int &num : nums) {
            pq.push(num);
            
            if(pq.size() > k) {
                pq.pop();
            }
        }
        
        return pq.top();
    }*/
    
    // Approach 4:- Quick Select | T.C:- O(n) avg, O(n*n) worst case
    int partition_algo(vector<int>& nums, int L, int R) {
        
        int p = nums[L];
        int i = L+1;
        int j = R;
        
        while(i <= j) {
            
            if(nums[i] < p && nums[j] > p) {
                swap(nums[i], nums[j]);
                
                i++;
                j--;
            }
            
            if(nums[i] >= p) {
                i++;
            }
            
            if(nums[j] <= p) {
                j--;
            }
        }
        
        swap(nums[j], nums[L]);
        return j;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        
        int L = 0;
        int R = n-1;
        
        int pivot_idx = 0;
        
        while(true) {
            
            pivot_idx = partition_algo(nums, L, R);
            
            if(pivot_idx == k-1) {
                break;
            }
            else if(pivot_idx > k-1) {
                R = pivot_idx-1;
            }
            else {
                L = pivot_idx+1;
            }
        }
        
        return nums[pivot_idx];

    }
};