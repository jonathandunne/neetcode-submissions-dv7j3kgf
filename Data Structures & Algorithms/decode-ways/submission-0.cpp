class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || !(s[0] - '0')) {
            return 0;
        }

        int prev2 = 1;
        int prev = 1;

        for (int i = 1; i < s.length(); i++) {
            int curr = 0;

            if (s[i] != '0') {
                curr += prev;
            }

            int twoDigit = ((s[i - 1] - '0') * 10) + (s[i] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                curr += prev2;
            }

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};
