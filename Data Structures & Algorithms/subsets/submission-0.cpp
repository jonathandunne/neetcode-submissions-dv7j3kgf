class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output = {{}};
        
        for (int i = 0; i < nums.size(); i++) {
            vector<vector<int>> prev = output;
            for (int j = 0; j < prev.size(); j++) {
                vector<int> push = prev[j];
                push.push_back(nums[i]);
                output.push_back(push);
            }
        }


        return output;
    }
};
