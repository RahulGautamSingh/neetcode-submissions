class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, len = s.length(), maxLen = 0, seen[128] = {0};

        for(int r = 0; r < len; r++){
            while(seen[s[r]] != 0){
                seen[s[l]]--;
                l++;
            }

            seen[s[r]]++;
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};
