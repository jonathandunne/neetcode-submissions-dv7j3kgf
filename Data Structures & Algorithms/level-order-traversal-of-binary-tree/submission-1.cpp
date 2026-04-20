/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> output;
        queue<TreeNode*> q;
        int level = 0;
        if (!root) {
            return output;
        }
        q.push(root);
        while (!q.empty()) {
            output.push_back({});
            int n = q.size();
            for (int i = 0; i < n; i++) {
                output[level].push_back(q.front()->val);
                if (q.front()->left) {
                    q.push(q.front()->left);
                }
                if (q.front()->right) {
                    q.push(q.front()->right);
                }
                q.pop();
            }
            level++;
        }
        return output;
    }
};
