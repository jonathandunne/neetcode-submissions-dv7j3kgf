class Solution {
private:
    unordered_map<int, int> memo;
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }

        if (memo.find(n) != memo.end()) {
            return memo[n];
        }

        int output = climbStairs(n - 1) + climbStairs(n - 2);
        memo[n] = output;
        return output;
    }
};
