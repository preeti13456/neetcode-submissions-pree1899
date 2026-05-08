class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adjList(n);
        for (auto& flight : flights)
            adjList[flight[0]].push_back({flight[1], flight[2]});

        vector<vector<int>> destHop(n, vector<int>(k+2, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, k+1}); // {cost, node, hops}

        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            int cost = temp[0], node = temp[1], hops = temp[2];

            if (node == dst) return cost;
            if (hops == 0) continue;

            for (auto& [adjNode, adjCost] : adjList[node]) {
                if (cost + adjCost < destHop[adjNode][hops - 1]) {
                    destHop[adjNode][hops - 1] = cost + adjCost;
                    pq.push({destHop[adjNode][hops - 1], adjNode, hops - 1});
                }
            }
        }
        return -1;
    }
};