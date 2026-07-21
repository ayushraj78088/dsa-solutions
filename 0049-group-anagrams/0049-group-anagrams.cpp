class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string str : strs) {
            vector<int> count(26);
            for (int i = 0; i < str.length(); i++) count[str[i] - 'a']++;

            string key = "";
            for (int i = 0; i < 26; i++) key += to_string(count[i]) + "#";

            mp[key].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto x : mp) {
            ans.push_back(x.second);
        }

        return ans;
    }
};