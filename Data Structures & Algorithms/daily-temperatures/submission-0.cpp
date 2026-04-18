class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> distances(temperatures.size(), 0);
        stack<pair<int, int>> tempStack;

        for (int i = 0; i < temperatures.size(); i++) {
            while (!tempStack.empty()) {
                pair<int, int> top = tempStack.top();
                if (temperatures[i] > top.first) {
                    tempStack.pop();
                    distances[top.second] = i - top.second;
                }
                else {
                    break;
                }
            }
            tempStack.push({temperatures[i], i});
        }

        return distances;
    }
};
