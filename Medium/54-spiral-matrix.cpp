class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;  //stores the final spiral order
        
        int m = matrix.size();       //no of rows
        int n = matrix[0].size();    //no of col
        
        //define boundaries of the current layer
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;
        
        //keep looping until boundaries overlap
        while (top <= bottom && left <= right) {
            
            //traverse the top row 
            for (int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }
            top++;  //move the top boundary down
            
            //traverse the right column 
            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;  //move the right boundary left
            
            //traverse the bottom row 
            //only if theres still a valid row remaining
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;  //move the bottom boundary up
            }
            
            //traverse the left column 
            //only if theres still a valid col remaining
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;  //move the left boundary right
            }
        }
        
        return result;  //final spiral traversal
    }
};