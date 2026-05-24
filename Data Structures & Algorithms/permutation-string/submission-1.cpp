class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        int lenS1 = s1.length(), lenS2 = s2.length();
        if(lenS1 > lenS2) return false;
        int freqs1[26] = {0};
        int freqs2[26] = {0};
        for (int i = 0; i < lenS1; i++) {
            freqs1[s1[i] - 'a']++;
            freqs2[s2[i] - 'a']++;
        }

        int l = 0, r = lenS1 - 1;
        for (; r < lenS2; r++) {
                if(r != lenS1-1){
                        freqs2[s2[r]-'a']++;
                }
            if (allMatch(freqs1, freqs2)) {
                return true;
            }
                freqs2[s2[l] - 'a']--;
                l++;
            
        }
        return false;
    };

   private:
    bool allMatch(int freqs1[], int freqs2[]) {
        for (int i = 0; i < 26; i++) {
            if (freqs1[i] != freqs2[i]) {
                return false;
            }
        }

        return true;
    }
};
