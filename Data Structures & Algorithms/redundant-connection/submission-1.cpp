class UnionFind
{
    public:
    UnionFind(int n)
    : parent_(n), rank_(n,0)
    {
        iota(parent_.begin(), parent_.end(), 0);
    }
    int Find(int x)
    {
        if(x!=parent_[x])
        {
            parent_[x] = Find(parent_[x]);
        }
        return parent_[x];
    }
    bool Union(int x, int y)
    {
        //1->2->3
        //1->2
        //rx = 1
        int rx = Find(x);
        //2->3
        //ry = 1;
        int ry = Find(y);
        if(rx==ry)
        {
            return false;
        }
        //it will comapre teh depth of first 
        if(rank_[rx]<rank_[ry])
        {
            swap(rx, ry);
        }
        //[[1,2],[1,3],[1,4],[3,4],[4,5]]

        // parent[4] = 1
        // parent[5] = 5
        // but for (4,5)
        // parent[5] = 1;

        //attache ry grouo under rx grouo 
        parent_[ry] = rx;
        //two group of equal height merge 
        if(rank_[rx]==rank_[ry])
        {
            rank_[rx]++;
        }
        return true;
    }
    private:
    vector<int>parent_;
    vector<int>rank_;

};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //we are using uniuon find to maintain the 
        //as we add edge to graph we join connected component using union
        //condition where we try to union vertices already connected mutually we found graph
        //1->2->3 , both 1 and 3 are connected 
        //bt 1->3 if already connected thre is a path 
        //and we have cycle 

        // we return last edge that creates loop
        //[[1,2],[1,3],[1,4],[3,4],[4,5]]
        
        //5
        const int n = edges.size();
        //6
        //[[],[], [], [], [], []]
UnionFind disjoin_set(n+1);

for(int i=0; i<n; i++)
{
    if(!disjoin_set.Union(edges[i][0], edges[i][1]))
    {
        return edges[i];
    }
}
return {};
    }
};
