class Solution {
    void merge(vector<int>& arr1, vector<int>& arr2) { 
        int n = arr1.size();
        int m = arr2.size();
        
        int i = n-1;
        int j = 0;
        
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
    
public:
    double findMedianSortedArrays(vector<int>& array1, vector<int>& array2) {
        int n = array1.size();
        int m = array2.size();
        int total_size = n+m;
        
        merge(array1, array2);
        
        // for(int &i : array1) cout << i << " ";
        // cout << endl;
        // for(int &i : array2) cout << i << " ";
        // cout << endl;
        
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
        
    }
};