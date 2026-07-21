class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temparatures) {
        stack<int> indexStack;
        int len = temparatures.size();
        vector<int> result;

        for(int i = len - 1; i >= 0; i--){
            if(indexStack.empty()){
                indexStack.push(i);
                result.push_back(0);
            } else {
                if(temparatures[i] < temparatures[indexStack.top()]){
                    result.push_back(indexStack.top() - i);
                    indexStack.push(i);
                } else {
                     while(!indexStack.empty() && temparatures[i] >= temparatures[indexStack.top()]){
                        indexStack.pop();
                     }
                     if(indexStack.empty()){
                          indexStack.push(i);
                          result.push_back(0);
                     } else {
                        result.push_back(indexStack.top() - i);
                        indexStack.push(i);
                     }
                }
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
