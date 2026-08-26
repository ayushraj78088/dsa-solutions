class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        
        vector<int> interval = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= interval[1]) interval[1] = max(interval[1], intervals[i][1]);
            else {
                ans.push_back(interval);
                interval = intervals[i];
            }
        }
        ans.push_back(interval);

        return ans;
    }
};