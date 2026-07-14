class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();                   //stores the number of rows in a matrix
        int col = matrix[0].size();                //stores number of columns
        for(int i =0; i < row; i++){               
            int left = 0;                        //points towards first column
            int right = col - 1;                 // last coulmn of current row
            while(left <= right){
                int mid = left  + (right - left)/2;
                if(matrix[i][mid] == target){          // if target found return the true
                    return true;
                }
                else if (matrix[i][mid] > target) {
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
        }
        return false;
    }
};
//Binary search complexity is o(logn)