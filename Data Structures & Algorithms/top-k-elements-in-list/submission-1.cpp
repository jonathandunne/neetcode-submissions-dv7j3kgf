class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> buckets(nums.size() + 1);
        unordered_map<int, int> freq;
        vector<int> output;

        for (int num : nums) {
            freq[num]++;
        }

        for (const auto& kv : freq) {
            buckets[kv.second].push_back(kv.first);
        }

        int pushed = 0;
        for (int i = buckets.size() - 1; i >= 0; i--) {
            for (int num : buckets[i]) {
                output.push_back(num);
                pushed++;
            }
            if (pushed >= k) {
                return output;
            }
        }

        return output;
    }
};
