class Solution {
public:

    string encode(vector<string>& strs) {
        // convert each string to the a string formed from ascii code of it's characters separated by commas
        // join them in a string by adding space as separator
        string res = "";
        for(auto& ch:strs){
            res += to_string(ch.length()) + '#' + ch;
        }

        return res;
    }

    vector<string> decode(string s) {
        // take the string
        // divide into separate strings using the space separator
        // decode each string back to character using the ascii code number
        vector<string> res = {};
        for(int i=0; i<s.length(); i++){
            string strLenStr = "";
            while((int)s[i] >= 48 && (int)s[i] <= 57){
                strLenStr += s[i];
                i++;
            }

            i++;

            int strLen = stoi(strLenStr);

            string sRes = "";
            while(strLen > 0){
                sRes += s[i];
                i++;
                strLen--;
            }

            i--;

            res.push_back(sRes);
        }

        return res;
    }
};
