class Solution {
public:
    void helper(vector<int>& nums, int idx, vector<int>& ans, vector<vector<int>>& finalAns) {
        if (idx == nums.size()) {
            finalAns.push_back(ans);
            return;
        }

        ans.push_back(nums[idx]);
        helper(nums, idx + 1, ans, finalAns);

        ans.pop_back();
        helper(nums, idx + 1, ans, finalAns);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> finalAns;
        vector<int> ans;

        helper(nums, 0, ans, finalAns);
        return finalAns;
    }
};