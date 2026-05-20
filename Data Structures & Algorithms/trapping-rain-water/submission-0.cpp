class Solution {
public:
    int trap(vector<int>& height) {
         int len = height.size();
        vector<int> left = {};
        left.push_back(height[0]);
        int leftMax = height[0];
        vector<int> right = {};
         right.push_back(height[len - 1]);
        int rightMax = height[len - 1];
       

// from left to right ie. fill the max height at left of index 
        for(int i=1; i<len; i++){
            if(leftMax < height[i]) leftMax = height[i];
            left.push_back(leftMax);
            
        }
// from right to left ie. fill the max height at right of index 
        for(int i=len-2; i>=0; i--){
            if(rightMax < height[i]) rightMax = height[i];
            right.push_back(rightMax);
            
        }

        // reverse the right vector
        reverse(right.begin(), right.end());

        int totalWater = 0;
        for(int i=0; i<len; i++){
            totalWater += min(left[i], right[i]) - height[i];
        }

        return totalWater;

    }
};
