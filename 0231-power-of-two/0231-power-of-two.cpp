class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Approach 2:- Bit Magic
        /*if(n <= 0) return false;
        
        if((n & n-1) == 0) {
            return true;
        }
        return false;*/
        
        // Approch 3:- built in function
        if(n <= 0) return false;
        int count = __builtin_popcount(n);
        
        return (count == 1) ? true : false;
    }
};