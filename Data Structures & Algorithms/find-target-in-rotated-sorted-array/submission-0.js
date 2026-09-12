class Solution {
    /**
     * @param {number[]} nums
     * @param {number} target
     * @return {number}
     */
    search(nums, target) {
        return this.bs(nums, 0, nums.length-1, target)
    }

    bs(nums, left, right, target){

        if((left === right || left > right) && target !== nums[left]) return -1;

         let mid = left + Math.floor((right - left)/2) ;

         if(target === nums[left]) return left;
         if(target === nums[right]) return right;
         if(target === nums[mid]) return mid;


        // left half is sorted
         if(nums[left] < nums[mid]){
            // target inside left half
            if(target >= nums[left] && target <= nums[mid]){
                return this.bs(nums, left, mid, target);
            }
              return this.bs(nums,mid+1,right, target);
         }

         else {
 if(target >= nums[mid] && target <= nums[right]){
                return this.bs(nums,mid+1,right, target);
            }
              return this.bs(nums,left,mid, target);

         }
    }
}
