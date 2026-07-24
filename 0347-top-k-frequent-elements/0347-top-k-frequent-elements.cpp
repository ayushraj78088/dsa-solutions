class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int num : nums) mp[num]++;

        vector<pair<int, int>> freq;
        for (auto x : mp) freq.push_back({x.second, x.first});

        sort(freq.begin(), freq.end());

        vector<int> ans;
        for (int i = freq.size() - 1; i >= 0 && k > 0; i--) {
            int ele = freq[i].second;
            ans.push_back(ele);
            k--;
        }

        return ans;
    }
};