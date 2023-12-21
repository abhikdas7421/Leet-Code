class Solution {
public:
    
    
    // Method 2 :- Gap Method
    void mergeInplace(vector<int> &arr, int start, int end) {
        int total_len = end - start + 1;
        int gap = (total_len / 2) + (total_len % 2); //ceil
        
        while(gap > 0) {
            int i = start, j = start + gap;
            
            while(j <= end) {
                if(arr[i] > arr[j]) {
                    swap(arr[i], arr[j]);
                }
                i++;
                j++;
            }
            
            gap = (gap <= 1) ? 0 : (gap / 2) + (gap % 2);
        }
    }
    
    void mergeSort(vector<int> &arr, int start, int end) {
        // base case
        if(start >= end) {
            return;
        }
        
        int mid = start + (end - start)/2;
        
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        mergeInplace(arr, start, end);
    }
    
    
    // Method 1
    /*
    void placeItRightPosition(vector<int> &arr, int s, int e) {
        int pe = arr[s];
        int pi = s;
        for(int i = s+1; i <= e; i++) {
            if(arr[i] < pe) {
                swap(arr[i], arr[pi]);
                pi = i;
            }
            else {
                break;
            }
        }
        
    }
    
    void mergeInplace(vector<int> &arr, int start, int mid, int end) {
        int i = start, j = mid+1;
        
        while(i <= mid && j <= end) {
            
            if(arr[i] <= arr[j]) {
                i++;
            }
            else { // arr[i] > arr[j]
                swap(arr[i], arr[j]);
                placeItRightPosition(arr, mid+1, end);
                i++;
            }
        }
        
    }
    
    void mergeSort(vector<int> &arr, int start, int end) {
        // base case
        if(start >= end) {
            return;
        }
        
        int mid = start + (end - start)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        mergeInplace(arr, start, mid, end);
    }
    */
    
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
        
    }
};