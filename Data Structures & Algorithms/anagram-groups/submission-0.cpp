class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> output;
        unordered_map<string, vector<string>> groups;
        
        for (string str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            if (groups.find(sortedStr) == groups.end()) {
                groups[sortedStr] = {str};
            }
            else {
                groups[sortedStr].push_back(str);
            }
        }

        for (const auto& kv : groups) {
            output.push_back(kv.second);
        }


        return output;
    }
};
