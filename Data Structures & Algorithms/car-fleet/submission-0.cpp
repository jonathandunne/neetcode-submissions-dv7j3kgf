class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> sortedCars;
        stack<double> times;
        
        for (int i = 0; i < speed.size(); i++) {
            sortedCars.push_back({position[i], speed[i]});
        }

        sort(sortedCars.begin(), sortedCars.end(), [](auto& a, auto& b) {
            return a.first > b.first;
        });

        for (pair<int, int> car : sortedCars) {
            double time = (double)(target - car.first) / (double)(car.second);
            if (times.empty() || time > times.top()) {
                times.push(time);
            }
        }


        return times.size();
    }
};
