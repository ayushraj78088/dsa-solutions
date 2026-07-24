class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int num : nums) freq[num]++;

        int n = nums.size();
        vector<vector<int>> bucket(n + 1);

        for (auto x : freq) {
            bucket[x.second].push_back(x.first);
        }

        vector<int> ans;
        for (int i = n; i >= 1 && k > 0; i--) {
            if (!bucket[i].empty()) {

                for (int x : bucket[i]) {
                    ans.push_back(x);
                    k--;
                    if (k == 0) break;
                }
            }
        }

        return ans;
    }
};