class Solution {
public:
vector<vector<bool>>visited;
bool dfs(int v, int p, vector<vector<int>>&graph)
{
    if(visited[v][0]) return !visited[v][1];
    visited[v][0] = true;
    visited[v][1] = true;
    bool ans = true;
    for(auto child: graph[v])
    {
        ans&=dfs(child, v, graph);
    }
    visited[v][1] = false;
    return ans;

}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         Input: numCourses = 2, prerequisites = [[0,1],[1,0]]

// Output: false
vector<vector<int>>graph(numCourses);
for(auto i : prerequisites)
{
    //[0,1]
    //0->1
    graph[i[0]].push_back(i[1]);
}
visited.clear();
visited.resize(numCourses, vector<bool>(2, false));
bool ans = true;
for(int i=0; i<numCourses; i++)
{
    if(!visited[i][0])
    {
        ans &= dfs(i, -1, graph);
    }
}
return ans;
    }
};
