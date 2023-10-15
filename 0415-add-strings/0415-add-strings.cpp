class Solution {
public:
    void addStringRE(string &num1, int p1, string &num2, int p2, int &carry, string &ans) {
        // base case
        if(p1 < 0 && p2 < 0 && carry == 0) {
            return;
        }


        // let's solve 1 case
        int n1 = (p1 >= 0 ? num1[p1] : '0') - '0';
        int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';
        int nSum = n1+n2+carry;
        int digit = nSum % 10;
        carry = nSum/10;

        ans.push_back(digit+'0');

        // RR
        addStringRE(num1, p1-1, num2, p2-1, carry, ans);
    }

    string addStrings(string num1, string num2) {
        int carry = 0;
        string ans = "";
        addStringRE(num1, num1.size()-1, num2, num2.size()-1, carry, ans);
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};