class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> res = {};
        for(int i=0; i<len-2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int target = 0 - nums[i];
               
               int l=i+1,r=len-1;

                while(l<r){
                    int sum = nums[l] + nums[r];
                    if(sum < target){
                        l++;
                    } else if(sum > target){
                        r--;
                    } else {
                        vector<int> curr = {nums[i], nums[l], nums[r]};
                        res.push_back(curr);
                        int leftNum = nums[l];
                        int rightNum = nums[r];
                        while(l<r && leftNum == nums[l] && rightNum == nums[r]) {
                            l++; r--;
                        }
                    }
                }
            
        }

        return res;
    }
};
