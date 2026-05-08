class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool>visited(n, false);
        int edgesused = 0, cost = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>minHeap;
        minHeap.push({0,0});
        while(edgesused < n)
        {
            auto[weight , node] = minHeap.top();
            minHeap.pop();
            if(visited[node]) continue;
            visited[node] = true;
            cost+=weight;
            edgesused++;

            for(int nei=0; nei<n; nei++)
            {
                if(!visited[nei])
                {
                    int dist = abs(points[node][0]-points[nei][0])+abs(points[node][1]-points[nei][1]);
                    minHeap.push({dist, nei});
                }
            }
        }
        return cost;
            }
};
