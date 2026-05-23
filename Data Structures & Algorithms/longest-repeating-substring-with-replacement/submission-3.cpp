class Solution {
   public:
    int characterReplacement(string s, int k) {
        int len = s.length();
        int l = 0, maxf = 0, res = 0;
        int count[26] = {0};

        for (int r = 0; r < len; r++) {
            count[s[r] - 'A']++;
            maxf = max(maxf, count[s[r] - 'A']);

            while ((r - l + 1) - maxf > k) {
                count[s[l]-'A']--;
                l++;
            }

            res = max(res, r-l+1);
        }

        return res;
    }
};
