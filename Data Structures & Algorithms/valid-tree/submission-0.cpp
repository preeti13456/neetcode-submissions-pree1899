class Solution {
public:
bool dfs(int parent, int node, vector<vector<int>>&graph, vector<bool>&visited)
{
    visited[node] = true;
    for(auto neighbor : graph[node])
    {
        if(!visited[neighbor])
        {
            if(!dfs(node, neighbor, graph, visited))
            
            return false;
        }
            else if(neighbor!=parent)
            {
            return false;
            }
    }
        return true;
    
}
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        for(auto & p : edges)
        {
            //0->1
            //0 = p[0]
            //1 = p[1]
            int x = p[0];
            int y=p[1];
            //0->1
            //1->0
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        vector<bool>visited(n, false);
        int connectedComponents = 0;
        for(int i=0; i<graph.size(); i++)
        {
            if(!visited[i])
            {
                if(connectedComponents)
                return false;
                if(!dfs(-1, i, graph, visited))
                return false;
                connectedComponents++;
            }
        }
        return true;
    }
};
