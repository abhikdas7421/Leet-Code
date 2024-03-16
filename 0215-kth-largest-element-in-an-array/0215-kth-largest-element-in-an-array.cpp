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
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq; // default max heap
        
        for(int &num : nums) {
            pq.push(num);
            
            if(pq.size() > k) {
                pq.pop();
            }
        }
        
        return pq.top();
    }
};