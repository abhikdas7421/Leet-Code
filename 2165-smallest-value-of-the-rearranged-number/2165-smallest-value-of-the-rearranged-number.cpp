class Solution {
public:
    long long smallestNumber(long long num) {
        if(num == 0) {
            return 0;
        }
        
        string str = to_string(num);
        long long ans;
        
        if(num > 0) {
            sort(str.begin(), str.end());
            
            int index = str.find_first_not_of('0');
            swap(str[0], str[index]);
            
            ans = stoll(str);
        }
        else {
            sort(str.begin(), str.end(), greater<char>());
            
            ans = stoll(str);
            ans *= -1;
        }
        
        return ans;
    }
};