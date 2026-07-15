class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>adj[numCourses];
        int count=0;
      vector<int>indegree(numCourses,0);
      for(int i=0;i<prerequisites.size();i++){
         int src = prerequisites[i][1];
            int dest = prerequisites[i][0];
        adj[dest].push_back(src);
        indegree[src]++;
      }
    
    queue<int>q;
    for(int i=0;i<numCourses;i++){
        if(indegree[i]==0){
            q.push(i);

        }
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        count++;

        for(int neighbour: adj[node]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
       
    }
     return count==numCourses;
    }
};