class Solution {
public:
    bool dfs(int course, const vector<vector<int>>& prereqMap, vector<int>& state) {
        if (state[course] == 1) { // Cycle
            return false;
        }
        if (state[course] == 2) { // Valid
            return true;
        }

        state[course] = 1;

        for (int i = 0; i < prereqMap[course].size(); i++) {
            if (!dfs(prereqMap[course][i], prereqMap, state)) {
                return false;
            }
        }
        state[course] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> prereqMap(numCourses);
        vector<int> state(numCourses, 0); // 0: unvisited, 1: visiting, 2: done and valid

        // Convert to map
        for (vector<int> prereq : prerequisites) {
            prereqMap[prereq[0]].push_back(prereq[1]);
        }

        // DFS
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, prereqMap, state)) {
                return false;
            }
        }
        return true;
    }
};
