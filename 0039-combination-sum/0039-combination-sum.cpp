class Solution {
public:
    void combinations(vector<int>& ans, vector<vector<int>>& finalAns, vector<int>& candidates, int target, int idx, int sum) {
        if (target < 0) return;

        if (idx == candidates.size()) {
            if (target == 0) {
                finalAns.push_back(ans);
            }
            return;
        }

        ans.push_back(candidates[idx]);
        combinations(ans, finalAns, candidates, target - candidates[idx], idx, sum + candidates[idx]);

        ans.pop_back();
        combinations(ans, finalAns, candidates, target, idx + 1, sum);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        vector<vector<int>> finalAns;

        combinations(ans, finalAns, candidates, target, 0, 0);
        return finalAns;
    }
};