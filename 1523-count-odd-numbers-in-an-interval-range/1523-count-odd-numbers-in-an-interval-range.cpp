class Solution {
public:
    int countOdds(int low, int high) {
        
        int n = high-low+1;
        
        int ans;
        if((low%2 == 0 && high%2 != 0) || (low%2 != 0 && high%2 == 0)) {
            ans = n/2;
        }
        else if(low%2 != 0 && high%2 != 0) {
            ans = ((n-1)/2)+ 1;
        }
        else if(low%2 == 0 && high%2 == 0) {
            ans = (n-1)/2;
        }
        
        return ans;
        
    }
};
