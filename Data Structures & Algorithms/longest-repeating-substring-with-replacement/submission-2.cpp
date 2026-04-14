class Solution {
public:
    int characterReplacement(string s, int k) {
        int longest = 0;
        int count[26] = {0};
        int greatest = 0;
        int left = 0;
        int right = 0;

        while (right < s.length()){
            count[s[right] - 'A']++;
            greatest = max(greatest, count[s[right] - 'A']);
            
            while ((right - left + 1) - greatest > k) {
                count[s[left] - 'A']--;
                left++;
            }

            longest = max(longest, (right - left + 1));
            right++;
        }



        return longest;
    }
};
