class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int num : nums) freq[num]++;

        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;

        for (auto x : freq) {
            pq.push({x.second, x.first});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> ans;
        while (!pq.empty()) {
            int ele = pq.top().second;
            ans.push_back(ele);

            pq.pop();
        }

        return ans;
    }
};