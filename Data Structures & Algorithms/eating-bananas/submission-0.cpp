class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *std::max_element(piles.begin(), piles.end());
        int speed = right;
        while (left <= right) {
            int mid = (left + right) / 2;
            int time = 0;
            for (int pile : piles) {
                time += ceil((double)pile / (double)mid);
            }
            if (time <= h) {
                speed = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return speed;
    }
};
