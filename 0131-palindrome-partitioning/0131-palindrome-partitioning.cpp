class Solution {
public:
    bool isPalindrome(string s, int si, int ei) {
        while (si <= ei) {
            if (s[si++] != s[ei--]) return false;
        }

        return true;
    }

    void helper(string s, int idx, vector<string>& ans, vector<vector<string>>& finalAns) {
        if (idx == s.length()) {
            finalAns.push_back(ans);
            return;
        }

        for  (int i = idx; i < s.length(); i++) {
            if (isPalindrome(s, idx, i)) {
                ans.push_back(s.substr(idx, i - idx + 1));
                helper(s, i + 1, ans, finalAns);
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> ans;
        vector<vector<string>> finalAns;

        helper(s, 0, ans, finalAns);

        return finalAns;
    }
};