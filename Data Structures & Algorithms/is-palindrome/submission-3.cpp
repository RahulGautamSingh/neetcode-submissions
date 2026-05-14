class Solution {
   public:
    bool isPalindrome(string s) {
        stack<char> st;
        string massagedS = "";
        int len = s.length();
        for (int i = 0; i < len; i++) {
            char c = s[i];
            if (((int)c >= 97 && (int)c <= 122) || ((int)c >= 48 && (int)c <= 57)) {
                massagedS += c;
            } else if((int)c >= 65 && int(c) <= 90){
                 massagedS += tolower(c);
            }

        }

        // cout << massagedS;


        int massagedLen = massagedS.length();
        int halfLine = massagedLen / 2 - 1;

        for (int i = 0; i <= halfLine; i++) {
            st.push(massagedS[i]);
        }

        int nextHalf = massagedLen % 2 == 0 ? halfLine + 1 : halfLine + 2;

        for (int i = nextHalf; i < massagedLen; i++) {
            if (st.top() == massagedS[i]) {
                st.pop();
            } else {
                return false;
            }
        }

        return true;
    }
};
