class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;

        for (int n : nums) {
            sum += n;
        }
        if (sum % 2) {
            return false;
        }

        int target = sum / 2;
        vector<bool> canReach(sum + 1, false);

        canReach[0] = true;

        for (int n : nums) {
            for (int i = sum; i >= n; i--) {
                canReach[i] = canReach[i] || canReach[i - n];
            }
        }

        return canReach[target];
    }
};
