class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses,0);

        for(auto &it : prerequisites){
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }

        queue<int> q;

        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0)
                q.push(i);
        }

        int cnt = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;

            for(auto neigh : adj[node]){
                indeg[neigh]--;
                if(indeg[neigh]==0)
                    q.push(neigh);
            }
        }

        return cnt == numCourses;
    }
};