class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        string s2Substr = s2.substr(0, s1.length());
        int freqS1[26] = {0};
        int freqS2[26] = {0};
        int matches = 0;

        for (char c : s1) {
            freqS1[c - 'a']++;
        }

        for (char c : s2Substr) {
            freqS2[c - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (freqS1[i] == freqS2[i]) {
                matches++;
            }
        }

        if (matches == 26) {
            return true;
        }

        for (int i = 0; i < s2.length() - s1.length(); i++) {
            int left = s2[i] - 'a';
            int right = s2[i + s1.length()] - 'a';

            // remove left char
            if (freqS2[left] == freqS1[left]) matches--;
            freqS2[left]--;
            if (freqS2[left] == freqS1[left]) matches++;

            // add right char
            if (freqS2[right] == freqS1[right]) matches--;
            freqS2[right]++;
            if (freqS2[right] == freqS1[right]) matches++;

            if (matches == 26) return true;
        }



        return false;
    }
};
