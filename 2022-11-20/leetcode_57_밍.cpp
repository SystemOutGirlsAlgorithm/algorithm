class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0;
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i++]);
        }
        
        if (i < intervals.size()) newInterval[0] = min(newInterval[0], intervals[i][0]);
        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[1] = max(newInterval[1], intervals[i++][1]);
        }
        ans.push_back(newInterval);
        
        while (i < intervals.size()) {
            ans.push_back(intervals[i++]);
        }
        
        return ans;
    }
};