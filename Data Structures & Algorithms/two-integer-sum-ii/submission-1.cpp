class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // left pointer .. 0, right pointer .. n-1
        // if sum(l+r)
        // < target; move left pointer 
        // > targer; move right pointer
        int len = numbers.size();
        int l = 0, r = len - 1;


        while(l < r){
            int sum = numbers[l] + numbers[r];
            if(sum < target) { l++; }
            else if(sum > target) { r--; }
            else { break; } 
        }

        vector<int> res = {l+1, r+1};

        return res;
    }
};
