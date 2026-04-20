class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[0] < b[0];
        });

        for (int i = 0; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int currEnd = intervals[i][1];
            while (i < intervals.size() - 1 && intervals[i + 1][0] <= currEnd) {
                currEnd = max(currEnd, intervals[i + 1][1]);
                i++;
            }
            merged.push_back({start, currEnd});
        }

        return merged;
    }
};
