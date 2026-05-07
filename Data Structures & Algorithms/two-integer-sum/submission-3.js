class Solution {
    /**
     * @param {number[]} nums
     * @param {number} target
     * @return {number[]}
     */
    twoSum(nums, target) {
        const len = nums.length;

        // for(let i=0; i<len; i++){
        //     for(let j=i+1; j<len; j++){
        //         if(nums[i]+nums[j] === target) return [i,j];
        //     }
        // }

        // use hashmap
        // I will store each instance of a number in hashmap
        // then when on an iteration
        // I will check if current target - nums[i] exists in hashmap or not

        const dict = new Map();
        for(const [index,value] of nums.entries()){
            dict.set(value, index);
        }
 for(const [index,value] of nums.entries()){
          if(dict.has(target-value) && index !== dict.get(target-value)){
            return [index, dict.get(target-value)];
          }
        }
    }
}
