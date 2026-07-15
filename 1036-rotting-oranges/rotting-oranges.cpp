// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
        
//         int rows=grid.size();
//         int cols=grid[0].size();
//         int ans=0;
//         queue<pair<pair<int,int>,int>>q;
//         int totaloranges=0;
//         int rottenoranges=0;

//         for(int i=0;i<rows;i++){
//             for(int j=0;j<cols;j++){
//                 if(grid[i][j]==1||grid[i][j]==2){
//                     totaloranges++;
//                 }
            
//             if(grid[i][j]==2){
//                 rottenoranges++;
//                 q.push({{i,j},0});
//             }
//             }
//         }
//         int drow[]={-1,0,1,0};
//         int dcol[]={0,1,0,-1};
//         while(!q.empty()){

//             pair<pair<int,int>,int>p=q.front();
//             q.pop();
//             int i=p.first.first;
//             int j=p.first.second;
//             int time=p.second;
//              ans=max(ans,time);
//             rottenoranges++;

//             for(int t=0;t<4;t++){
//                 int newi=i+drow[t];
//                 int newj=j+dcol[t];
//                 if(newi>=0 && newi<rows&&newj>=0 && newj<cols&& grid[newi][newj]==1){
//                     q.push({{newi,newj},time+1});
//                     grid[newi][newj]=2;
//                 }
//             }


//         }
    
//         if(totaloranges == rottenoranges)
//             return ans;

//         return -1;


//     }
// };





class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<pair<int,int>,int>> q;

        int totaloranges = 0;
        int rottenoranges = 0;
        int ans = 0;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {

                if(grid[i][j] == 1 || grid[i][j] == 2) {
                    totaloranges++;
                }

                if(grid[i][j] == 2) {
                    rottenoranges++;
                    q.push({{i, j}, 0});
                }
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()) {

            pair<pair<int,int>,int> p = q.front();
            q.pop();

            int i = p.first.first;
            int j = p.first.second;
            int time = p.second;

            ans = max(ans, time);

            for(int t = 0; t < 4; t++) {

                int newi = i + drow[t];
                int newj = j + dcol[t];

                if(newi >= 0 && newi < rows &&
                   newj >= 0 && newj < cols &&
                   grid[newi][newj] == 1) {

                    grid[newi][newj] = 2;
                    rottenoranges++;

                    q.push({{newi, newj}, time + 1});
                }
            }
        }

        if(totaloranges == rottenoranges)
            return ans;

        return -1;
    }
};