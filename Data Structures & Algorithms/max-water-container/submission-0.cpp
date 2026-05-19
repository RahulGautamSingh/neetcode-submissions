class Solution {
public:
    int maxArea(vector<int>& heights) {
        int len = heights.size();
        int l = 0, r = len - 1;
        int maxA = 0;

        while(l < r){
            int minH = min(heights[l], heights[r]);
            int distance = r - l;
            int area = minH * distance;
            maxA = max(area, maxA);

            if(heights[l] < heights[r]) l++;
            else r--;
        }

        return maxA;
    }
};
