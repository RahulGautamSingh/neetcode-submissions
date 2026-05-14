class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
              unordered_set<int> s = {};
              for(auto num:nums){
                if(s.find(num) != s.end()) continue;
                s.insert(num);
              }

              int maxCount = 0;
              for(auto it:s){
                if(s.find(it - 1) == s.end()){
                int count = 1;
                int nextNum = it + 1;
                while(s.find(nextNum) != s.end()){
                    count++;
                    nextNum++;
                }
                maxCount = max(maxCount, count);
                
                }
              }

              return maxCount;
    }
};
