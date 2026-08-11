class Solution {
public:

    int binary_search(int low, int high, int target, vector<int>& nums)    {

        if(low > high) return -1;


        int mid = low + (high - low) / 2;

        
        if(nums[mid] == target) return mid;
        else if (nums[mid] < target) 
            return  binary_search(mid+1, nums.size() - 1, target, nums);
        else
            return binary_search(low, mid-1, target, nums);
    }
    int search(vector<int>& nums, int target) {
        return binary_search(0, nums.size() - 1, target, nums);
    }
};
