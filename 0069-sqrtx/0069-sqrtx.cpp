class Solution {
public:
    int mySqrt(int x) {
        if(x == 1) return 1;
        
        int start = 1, end = x/2;
        int mid = start + (end-start)/2;
        int ans = 0;
        
        while(start <= end) {
            if(mid  == x/mid) {
                return ans = mid;
            }
            else if(mid < x/mid) {
                ans = mid;
                start = mid+1;
            }
            else {
                end = mid-1;
            }
            
            mid = start + (end-start)/2;
        }
        
        return ans;
        
    }
};