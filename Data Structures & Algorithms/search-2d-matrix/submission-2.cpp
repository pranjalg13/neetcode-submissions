class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int low = 0; int high = (n * m) - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            int matrixele = matrix[mid/m][mid%m];
            if(matrixele == target) return true;
            else if(matrixele > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return false;
    }
};
