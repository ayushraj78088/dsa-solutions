class Solution {
public:
    void reverseString(vector<char>& s) {
       if (s.size() == 0) return;

       char str = s[0];
       s.erase(s.begin());

       reverseString(s);

       s.push_back(str);
    }
};