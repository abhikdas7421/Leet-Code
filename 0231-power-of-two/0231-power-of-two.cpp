class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Approach 1:- 
        /*if(n <= 0) return false;
        
        if(n == 1) return true;
        
        return (n%2 == 0) && isPowerOfTwo(n/2);*/
        
        // Approach 2:- Bit Magic | T.C -> O(logn)
        /*if(n <= 0) return false;
        
        if((n & n-1) == 0) {
            return true;
        }
        return false;*/
        
        // Approch 3:- built in function | T.C -> O(logn)
        /*if(n <= 0) return false;
        
        int count = __builtin_popcount(n);
        return (count == 1) ? true : false;*/
        
        // Approch 4:- Best Approach
        if(n <= 0) return false;
        int x = 1073741824;
        
        return (x%n == 0) ? true : false;
        
    }
};