class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;

        for (int i = 0; i < heights.size() - 1; i++) {
            for (int j = 0; j < heights.size(); j++) {
                maxArea = max(maxArea, abs(i - j) * min(heights[i], heights[j]));
            }
        }

        return maxArea;
    }
};
