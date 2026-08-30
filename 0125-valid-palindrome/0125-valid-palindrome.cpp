class Solution {
public:
    string str(string s) {
        string ans = "";

        for (char ch : s) {
            if (isalnum(ch)) {
                ans += tolower(ch);
            }
        }

        return ans;
    }

    bool isValid(string& s, int i, int n) {
        if (i >= n/2) return true;

        if (s[i] != s[n - i - 1]) return false;
        return isValid(s, i + 1, n);
    }

    bool isPalindrome(string s) {
        s = str(s);
        return isValid(s, 0, s.length());
    }
};