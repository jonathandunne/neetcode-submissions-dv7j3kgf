class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> closest;
        sort(points.begin(), points.end(), [](auto& a, auto& b) {
            return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]);;
        });
        for (int i = 0; i < k; i++) {
            closest.push_back(points[i]);
        }
        return closest;
    }
};
