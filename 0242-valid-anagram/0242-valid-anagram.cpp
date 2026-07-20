class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        int fq[26] = {0};

        for (char c : s) fq[c - 'a']++;
        for (char c : t) fq[c - 'a']--;

        for (int x : fq) {
            if (x != 0) return false;
        }

        return true;
    }
};