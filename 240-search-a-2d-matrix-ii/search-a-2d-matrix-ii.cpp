class Solution {
public:
 
 bool solve(vector<vector<int>>&matrix, int row, int col, int target){

    if(row>=matrix.size() || col<0){
        return false;
    }
    if(matrix[row][col]==target){
        return true; 
        
    }
    if(matrix[row][col]>target)
        return solve(matrix, row, col-1, target);
      
    
      return solve(matrix, row+1, col, target);
 }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int n=matrix.size();
       int m=matrix[0].size();
       return solve(matrix,0, m-1, target); 
    }
};