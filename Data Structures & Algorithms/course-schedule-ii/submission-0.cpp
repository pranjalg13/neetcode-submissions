class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses,0);
        vector<int> topo;

        for(auto &it : prerequisites){
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }

        queue<int> q;
        

        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto neigh : adj[node]){
                indeg[neigh]--;
                if(indeg[neigh]==0)
                    q.push(neigh);
            }
        }
        if(topo.size()==numCourses) return topo;
        return {};
    }
};
