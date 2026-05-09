class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       
        // use heaps

        // use maxHeap key=
        priority_queue<pair<int, int>> maxHeap;

        // get frequency mapping first
        unordered_map<int, int> freq = {};

        for(auto i:nums){
            if(freq.find(i) != freq.end()){
                freq[i] = freq[i] + 1;
            } else {
                freq[i] = 1;
            }
        }

        for(auto& i:freq){
            maxHeap.push({i.second, i.first});
        }

        int count = 0;
        vector<int> res = {};
        while(count < k){
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
            count++;
        }
       
       return res;
    }
};
