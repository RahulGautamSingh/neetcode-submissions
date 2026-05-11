class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int allProduct = 1;
        bool hasZero = false;
        int countZeroes = 0;
        for(auto& num:nums){
            if(num != 0){
            allProduct *= num;
            } else {
                hasZero = true;
                countZeroes++;
            }
        }

        for(int i=0; i<nums.size(); i++){
           
            if(hasZero == true){
                if(nums[i] == 0){
                    if(countZeroes == 1){
                    nums[i] = allProduct;
                    } else {
                        nums[i] = 0;
                    }
                } else {
                    nums[i] = 0;
                }
            } else {
                 nums[i] = allProduct / nums[i];
            }
        }

        return nums;
    }
};
