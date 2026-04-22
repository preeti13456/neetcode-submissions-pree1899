class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       //max heap of size k will keep track of k closest points and remev teh farthest points when it exceeds k 
       priority_queue<pair<int, vector<int>>>h;
       vector<vector<int>>res;
       for(auto point: points)
       {
        //[0,2]
        //d = 0*0 +2*2 = 4
        int d = point[0]*point[0] + point[1]*point[1];
        h.push({d,point});
        //[[(8, [2,2]), (4, [0,2]), (4, [2,0])]
        if(h.size()>k)
        {
            //pop (8, [2,2])
            h.pop();
        }
       } 
       while(!h.empty())
       {
        //res = [[0,2], [2,0]]
        res.push_back(h.top().second);
        h.pop();
       }
       return res;
    }
};
