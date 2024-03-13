class Solution {
public:
    int pivotInteger(int n) {
        int left = 1;
        int right = (n*(n+1))/2;
        int i = 1;
        
        while(i <= n) {
            if(left == right) {
                return i;
            }
            
            left += (i+1);
            right -= i;
            i++;
        }
        
        return -1;
        
    }
};