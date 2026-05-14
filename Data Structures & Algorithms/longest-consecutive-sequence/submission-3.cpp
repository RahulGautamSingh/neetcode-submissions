class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
              unordered_map<int, bool> s = {};
              for(auto num:nums){
                if(s.find(num) != s.end()) continue;
                s.insert({num, true});
              }

int maxCount = 0;
              for(auto it:s){
                if(it.second == true){
                int count = 1;
                int nextNum = it.first + 1;
                while(s.find(nextNum) != s.end()){
                    s.insert({nextNum, false});
                    count++;
                    nextNum++;
                }
                maxCount = max(maxCount, count);
                }
              }

              return maxCount;
    }
};
