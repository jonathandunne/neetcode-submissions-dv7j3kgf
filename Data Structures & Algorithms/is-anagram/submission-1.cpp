class Solution {
public:
    bool isAnagram(string s, string t) {
        int chars[26] = {0};

        for (char c : s) {
            chars[c - 'a']++;
        }

        for (char c : t) {
            chars[c - 'a']--;

            if (chars[c - 'a'] < 0) {
                return false;
            }
        }

        for (int c : chars) {
            if (c != 0) {
                return false;
            }
        }

        return true;
    }
};
