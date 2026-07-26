class Solution {
public:
    void helper(vector<vector<int>>& finalAns, vector<int>& ans, vector<int>& nums, int n, int idx) {
        if (idx == n) {
            finalAns.push_back(ans);
            return;
        }

        ans.push_back(nums[idx]);
        helper(finalAns, ans, nums, nums.size(), idx + 1);

        ans.pop_back();
        helper(finalAns, ans, nums, nums.size(), idx + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> finalAns;
        vector<int> ans;

        helper(finalAns, ans, nums, nums.size(), 0);

        return finalAns;
    }
};