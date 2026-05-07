class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //Topological sort is only valid for DAG (directed acyclic graph)
        //u apears only beforev u->v 

        // detect a graph has cucle uses DFS 
        //but we need to maintain ordering of the graph nodes so we use BFS
        vector<int>indegree(numCourses, 0);
        vector<vector<int>>adj(numCourses);
        vector<int>res;
        for(auto &p : prerequisites)
        {
            indegree[p[1]]++;
            adj[p[0]].push_back(p[1]);
        }
        queue<int>q;
        for(int i=0; i<numCourses; i++)
        
            //source node hai
            if(indegree[i]==0) q.push(i);
            int finished = 0;
            while(!q.empty())
            {
                int crs = q.front(); q.pop();
                res.push_back(crs);
                finished++;
                for(int pre : adj[crs])
                {
                    indegree[pre]--;
                    if(indegree[pre]==0) q.push(pre);
                }
            }
            if(finished!=numCourses) return {};
            reverse(res.begin(), res.end());
            return res;
        }
    
};
