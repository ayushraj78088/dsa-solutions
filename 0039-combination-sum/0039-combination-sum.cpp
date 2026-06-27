class Solution {
public:
    void helper(vector<vector<int>>& finalAns, vector<int>& ans, int idx, int target, vector<int>& candidates) {
        if (target < 0) return;

        if (idx == candidates.size()) {
            if (target == 0) finalAns.push_back(ans);
            return;
        }

        ans.push_back(candidates[idx]);
        helper(finalAns, ans, idx, target - candidates[idx], candidates);
        
        ans.pop_back();
        helper(finalAns, ans, idx + 1, target, candidates);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> finalAns;
        vector<int> ans;

        helper(finalAns, ans, 0, target, candidates);
        return finalAns;
    }
};