class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minBuy = INT_MAX;

        for (int price : prices) {
            maxProfit = max(maxProfit, price - minBuy);
            minBuy = min(price, minBuy);
        }

        return maxProfit;
    }
};
