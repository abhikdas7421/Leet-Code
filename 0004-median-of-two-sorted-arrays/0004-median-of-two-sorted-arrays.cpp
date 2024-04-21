class Solution {
public:
    // Approach:- 1 | T.C:- O(nlogn + mlogm) | S.C:- O(1)
    /*void merge(vector<int>& arr1, vector<int>& arr2) { 
        int n = arr1.size();
        int m = arr2.size();
        
        int i = n-1, j = 0;
        
        while(i >= 0 && j < m) { // O(n)
            if(arr1[i] > arr2[j]) {
                swap(arr1[i], arr2[j]);
                i--;
                j++;
            }
            else {
                break;
            }
        }
        
        sort(arr1.begin(), arr1.end()); //O(nlogn)
        sort(arr2.begin(), arr2.end()); //O(mlogm)
    }
    
    double findMedianSortedArrays(vector<int>& array1, vector<int>& array2) {
        int n = array1.size();
        int m = array2.size();
        int total_size = n+m;
        
        merge(array1, array2);
        
        if(total_size&1 == 1) { // odd size
            int mid = total_size/2;
            
            if(n > mid) {
                return array1[mid];
            }
            else {
                return array2[mid-n];
            }
        }
        else { // even size
            int mid = total_size/2;
            
            if(n > mid) {
                return double((array1[mid]+array1[mid-1])/2.0);
            }
            else if(mid-n-1 >= 0){
                return double((array2[mid-n]+array2[mid-n-1])/2.0);
            }
            else {
                return double((array1[n-1]+array2[0])/2.0);
            }
        }
        
    }*/
    
    // Approach:- 2 | T.C:- O(n)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        int total_size = n+m;
        int mid = total_size/2;
        
        int element1 = 0;
        int element2 = 0;
        
        int i = 0, j = 0, k = 0;
        
        while(i < n && j < m) {
            
            if(nums1[i] < nums2[j]) {
                
                if(k == mid-1) {
                    element1 = nums1[i];
                }
                
                if(k == mid) {
                    element2 = nums1[i];
                }
                
                i++;
            }
            else  {
                if(k == mid-1) {
                    element1 = nums2[j];
                }
                
                if(k == mid) {
                    element2 = nums2[j];
                }
                
                j++;
            }
            
            k++;
        }
        
        while(i < n) {
            if(k == mid-1) {
                    element1 = nums1[i];
                }
                
            if(k == mid) {
                element2 = nums1[i];
            }
            
            i++;
            k++;
        }
        
        while(j < m) {
            if(k == mid-1) {
                    element1 = nums2[j];
                }
                
            if(k == mid) {
                element2 = nums2[j];
            }
                
            j++;
            k++;
        }
        
        if(total_size & 1 == 1) {
            return element2;
        }
        else {
            return (element1 + element2)/2.0;
        }
    }
};