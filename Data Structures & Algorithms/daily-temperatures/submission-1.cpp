class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> distances(temperatures.size(), 0);
        stack<int> tempStack;

        for (int i = 0; i < temperatures.size(); i++) {
            while (!tempStack.empty()) {
                int top = tempStack.top();
                if (temperatures[i] > temperatures[top]) {
                    tempStack.pop();
                    distances[top] = i - top;
                }
                else {
                    break;
                }
            }
            tempStack.push(i);
        }

        return distances;
    }
};
