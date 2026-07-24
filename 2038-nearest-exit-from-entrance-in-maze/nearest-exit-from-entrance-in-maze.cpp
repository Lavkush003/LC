class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();
        queue<pair<int,int>>q;

        q.push({entrance[0],entrance[1]});

        maze[entrance[0]][entrance[1]]='+';
       int steps=0;

       int dx[4]={-1,1,0,0};
       int dy[4]={0,0,-1,1}; 

       while(!q.empty()){

        int size=q.size();
        steps++;
        while(size--){
            auto curr=q.front();
            q.pop();
            int x=curr.first;
            int y=curr.second;

            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];

                if(nx>=0 && nx<m && ny>=0 && ny<n && maze[nx][ny]=='.' ){
                    if(nx==0 || nx==m-1 || ny ==0 || ny ==n-1) return steps;

                    maze[nx][ny]='+';

                    q.push({nx,ny});
                }
            }
        }
       }
       return -1;

    }
};