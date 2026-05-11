class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int allProduct = 1;
        // bool hasZero = false;
        // int countZeroes = 0;
        // for(auto& num:nums){
        //     if(num != 0){
        //     allProduct *= num;
        //     } else {
        //         hasZero = true;
        //         countZeroes++;
        //     }
        // }

        // for(int i=0; i<nums.size(); i++){

        //     if(hasZero == true){
        //         if(nums[i] == 0){
        //             if(countZeroes == 1){
        //             nums[i] = allProduct;
        //             } else {
        //                 nums[i] = 0;
        //             }
        //         } else {
        //             nums[i] = 0;
        //         }
        //     } else {
        //          nums[i] = allProduct / nums[i];
        //     }
        // }

        // return nums;

        // left prefix sum excluding current element
        int len = nums.size();
        vector<int> lpp(len, 1);
        lpp[0] = 1;
        int allProd = nums[0];
        for(int i=1; i<len; i++){
            lpp[i] = allProd;
            allProd *= nums[i];
        }

        vector<int> rpp(len, 1);
        rpp[len - 1] = 1;
        allProd = nums[len - 1];
        for(int i=len-2; i>-1; i--){
            rpp[i] = allProd;
            allProd *= nums[i];
        }

        vector<int> res(len,1);
        for(int i=0; i<len; i++){
            res[i] = rpp[i] * lpp[i];
        }

        return res;
    }
};
