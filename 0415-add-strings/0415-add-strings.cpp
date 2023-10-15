class Solution {
public:
    string addStringRE(string num1, int p1, string num2, int p2, int carry) {
        // base case
        if(p1 < 0 && p2 < 0 && carry == 0) {
            string ans = "";
            return ans;
        }


        // let's solve 1 case
        int n1 = (p1 >= 0 ? num1[p1] : '0') - '0';
        int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';
        int nSum = n1+n2+carry;
        int digit = nSum % 10;
        carry = nSum/10;

        string ans = "";
        ans.push_back(digit+'0');

        // RR
        ans += addStringRE(num1, p1-1, num2, p2-1, carry);

        return ans;


    }

    string addStrings(string num1, string num2) {
        
        string ans = addStringRE(num1, num1.size()-1, num2, num2.size()-1, 0);
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};