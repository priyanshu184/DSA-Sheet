class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;                   // This will store the spiral order

        int rows = matrix.size();          // Number of rows
        if (rows == 0) return ans;         // If matrix is empty, return empty vector

        int cols = matrix[0].size();       // Number of columns

        // Boundaries of the current layer
        int top = 0;                       // Topmost row not yet processed
        int bottom = rows - 1;             // Bottommost row not yet processed
        int left = 0;                      // Leftmost column not yet processed
        int right = cols - 1;              // Rightmost column not yet processed

        // Keep going while there is a valid rectangle left
        while (top <= bottom && left <= right) {

            // 1. Go from left to right on the top row
            for (int j = left; j <= right; j++) {
                ans.push_back(matrix[top][j]);
            }
            top++;  // Top row is done, move it down

            // 2. Go from top to bottom on the right column
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;  // Right column is done, move it left

            // 3. Go from right to left on the bottom row (if still valid)
            if (top <= bottom) {           // Check to avoid double processing
                for (int j = right; j >= left; j--) {
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--;  // Bottom row is done, move it up
            }

            // 4. Go from bottom to top on the left column (if still valid)
            if (left <= right) {           // Check to avoid double processing
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;   // Left column is done, move it right
            }
        }

        return ans;                        // Return the spiral order
    }
};
