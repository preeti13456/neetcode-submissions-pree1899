class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //res =[[1,5]]
        vector<vector<int>>res{newInterval};

//[[1,3],[4,6]]

//[1,3]

//[4,6]
        for(auto inter : intervals)
        {
            //5 < 1 No
//5<4 No
            if(res.back().back()<inter.front())
            res.push_back(inter);

//3<2no
//6<5 no
            else if(inter.back()<res.back().front())
            {
                res.push_back(inter);
                swap(res.back(), res[res.size()-2]);
            }
            else //res.back.front = min(2, 1) = 1
            //res.back.front = min()
            {
                res.back().front() = min(res.back().front(), inter.front());
                //res.back().back() = max(5, 3) = 5
                res.back().back() = max(res.back().back(), inter.back());
            }
        }
        //res=[[1,5]]
        return res;
    }
};
