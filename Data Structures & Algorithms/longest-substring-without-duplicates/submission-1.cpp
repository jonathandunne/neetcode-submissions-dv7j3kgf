class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        unordered_map<char, int> lastFound;
        int maxLength = 0;

        for (int i = 0; i < s.length(); i++) {
            if (lastFound.find(s[i]) != lastFound.end()) {
                left = max(left, lastFound[s[i]] + 1);
            }
            lastFound[s[i]] = i;
            cerr << left << " " << i << endl;
            maxLength = max(maxLength, 1 + i - left);
        }

        return maxLength;
    }
};
