class Solution {
public:
    void helper(vector<int>& candidates, int target, vector<int>& ans, vector<vector<int>>& finalAns, int idx) {
        if (target == 0) {
            finalAns.push_back(ans);
            return;
        }

        if (target < 0 || idx == candidates.size()) return;

        if (target >= candidates[idx]) {
            ans.push_back(candidates[idx]);
            helper(candidates, target - candidates[idx], ans, finalAns, idx);
            ans.pop_back();
        }

        helper(candidates, target, ans, finalAns, idx + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        vector<vector<int>> finalAns;

        helper(candidates, target, ans, finalAns, 0);

        return finalAns;
    }
};