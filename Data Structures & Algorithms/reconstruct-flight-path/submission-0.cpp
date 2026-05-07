class Solution {
    private:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>>adj;
    vector<string>res;
    void dfs(string node)
    {
        while(!adj[node].empty())
        {
            string next = adj[node].top();
            adj[node].pop();
            dfs(next);
        }
        res.push_back(node);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //use each ticket exactly once
        //eulerian path use every edge exactly once 
        //Airports nodes
        //tickets edges that are directed 
        for(vector<string>&tick : tickets)
        {
            adj[tick[0]].push(tick[1]);
        }
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};
