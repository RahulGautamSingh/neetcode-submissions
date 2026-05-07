class Solution {
    /**
     * @param {number[]} nums
     * @return {boolean}
     */
    hasDuplicate(nums) {
        // to check dupliacates we can do a loop and find any number which already present in the map
        const seen = new Set();
        for(const num of nums){
            if(seen.has(num)){
                return true;
            }

            seen.add(num);
        }

        return false;
    }
}
