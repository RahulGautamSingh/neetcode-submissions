class Solution {
public:

    bool binary_search(int low, int high, int target, vector<vector<int>>& matrix, int rowLen, int colLen) {
        if(low > high) return false;

        int mid = low + (high - low) / 2;
        int row = mid / colLen;
        int col = mid % colLen;
        int val = matrix[row][col];

        if(val == target) return true;
        if(val < target) return binary_search(mid + 1, high, target, matrix, rowLen, colLen);
        return binary_search(low, mid - 1, target, matrix, rowLen, colLen);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // m => row
        // n => column

        // length of new row = m*n
        // imagine it is a long line of length m*n
        // to get row/col from value between 0-m*n
        // val/n = row & val/m = col

        int m = matrix.size();
        int n = matrix[0].size();

        return binary_search(0, m*n-1, target, matrix, m, n);
    }
};
