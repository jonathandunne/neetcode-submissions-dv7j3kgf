class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> closest;
        sort(points.begin(), points.end(), [](auto& a, auto& b) {
            return sqrt(pow(a[0], 2) + pow(a[1], 2)) < sqrt(pow(b[0], 2) + pow(b[1], 2));
        });
        for (int i = 0; i < k; i++) {
            closest.push_back(points[i]);
        }
        return closest;
    }
};
