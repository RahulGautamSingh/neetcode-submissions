class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashMap = {};

        for(int i = 0; i < strs.size(); i++){
            // make a key using chars in strs[i]
            int keyArr[26] = {0};
            for(int j = 0; j < strs[i].length(); j++){
                int key_index = (int)strs[i][j] - 97;
                keyArr[key_index]++;
            }

            string key = "";
            for(int k = 0; k < 26; k++){
                key += to_string(keyArr[k]) + ',';
            }

            hashMap[key].push_back(strs[i]);
        }

        vector<vector<string>> res;
        for(auto& item: hashMap){
            res.push_back(item.second);
        }

        return res;
    }
};
