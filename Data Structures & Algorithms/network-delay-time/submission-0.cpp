class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //since we have to find shortst time it took to reach all nodes will use dijkstra algo
// times = [[1,2,1],[2,3,1],[1,4,4],[3,4,1]], n = 4, k = 1
        //build adjaency list 
        //src -> {destination newtworkDelay}
    
        vector<vector<pair<int, int>>>adj(n+1);
        for(auto& t : times)
        {
            adj[t[0]].push_back({t[1], t[2]});
        }


        vector<int>dist(n+1, INT_MAX);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

pq.push({0, k});
dist[k] = 0;
//dist=[infinity, 0, infinity, infinity, infinity ]

while(!pq.empty())
{
    //pop the smallest ndoe from min heap
    auto[time, node] = pq.top();
    pq.pop();


for(auto &[next, w]: adj[node])
{
    //pq = [(0, 1)], 0 is minimum time taken and 1 is node
    //0+1 < dist[2]
    //1<infinity 
    if(time+w<dist[next])
    {
        //dist[2] = 1
        dist[next] = time + w;
        //pq = {1,2}
        //
        pq.push({dist[next], next});
    }
}

}
int ans = *max_element(dist.begin()+1, dist.end());
return ans ==INT_MAX ? -1 : ans;


        
    }
};
