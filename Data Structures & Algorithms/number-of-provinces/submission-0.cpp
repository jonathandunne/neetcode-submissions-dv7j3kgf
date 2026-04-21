class Solution {
public:
    void dfs(int index, vector<vector<int>>& isConnected, vector<bool>& visited, int n) {
        visited[index] = true;
        for (int i = 0; i < n; i++) {
            if (isConnected[index][i] && !visited[i]) {
                dfs(i, isConnected, visited, n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                provinces++;
                dfs(i, isConnected, visited, n);
            }
        }

        return provinces;
    }
};