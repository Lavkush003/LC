class Solution {
    public boolean hasValidPath(char[][] grid) {

  int m=grid.length;
  int n=grid[0].length;

  if((m+n-1)%2!=0){
    return false;
  }

  if(grid[0][0]==')'){
    return false;
  }

  if(grid[m-1][n-1]=='('){
    return false;
  }


   boolean[][][] dp = new boolean[m][n][m + n];
   dp[0][0][1] = true;

  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){

        if(i==0 && j==0){
            continue;
        }
        for(int balance=0;balance<m+n;balance++){
            int newbalance;

            if(grid[i][j]=='('){
                newbalance=balance+1;
            }else{
                newbalance=balance-1;
            }
            if(newbalance<0 || newbalance>=m+n){
                continue;
            }
            if(i>0 && dp[i-1][j][balance]){
                dp[i][j][newbalance]=true;
            }
            if(j>0 && dp[i][j-1][balance]){
                dp[i][j][newbalance]=true;
            }

        }
    }
  }
  
        
  return dp[m-1][n-1][0];

        
    }
}