class Solution {
public:
    int trap(vector<int>& height) {
        int totalWater = 0;
        vector<int> maxRight(height.size(), 0);
        vector<int> maxLeft(height.size(), 0);

        for (int i = 1; i < height.size(); i++) {
            maxLeft[i] = max(maxLeft[i - 1], height[i - 1]);
        }

        for (int i = height.size() - 2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i + 1], height[i + 1]);
        }

        for (int i = 0; i < height.size(); i++) {
            totalWater += max(0, min(maxRight[i], maxLeft[i]) - height[i]);
        }


        return totalWater;
    }
};
