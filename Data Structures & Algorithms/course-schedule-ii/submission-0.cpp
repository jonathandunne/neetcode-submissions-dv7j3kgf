class Solution {
public:
    bool dfs(int course, vector<int>& state, const vector<vector<int>>& prereqMap, vector<int>& order) {
        if (state[course] == 1) {
            return false;
        }
        if (state[course] == 2) {
            return true;
        }

        state[course] = 1;
        for (int c : prereqMap[course]) {
            if (!dfs(c, state, prereqMap, order)) {
                return false;
            }
        }
        state[course] = 2;
        order.push_back(course);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
        vector<int> state(numCourses, 0);
        vector<vector<int>> prereqMap(numCourses);

        for (vector<int> prereq : prerequisites) {
            prereqMap[prereq[0]].push_back(prereq[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, state, prereqMap, order)) {
                return {};
            }
        }


        return order; 
    }
};
