class CountSquares {
public:
map<pair<int, int>, int>points;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        points[{point[0], point[1]}]++;
        //[]. add [1,1] => [[1,1], [2,2], [1,2]]
    }
    
    int count(vector<int> point) {
        //point = [2,1]
        int res = 0;
        int x = point[0]; //x=2
        int y = point[1]; //y=1
        for(auto& [k,cnt] : points)
        {
            //x2=1, y2=1
            int x2 = k.first, y2=k.second;
//dx = 2-1 = 1, dy=1-1 = 0
            int dx = x-x2, dy = y-y2;
            if(dx==0 || dy==0) continue;
            if(abs(dx)!=abs(dy)) continue;
            if(points.count({x,y2})&&points.count({x2,y}))
            res+=cnt*points[{x, y2}]*points[{x2,y}];


        }
        return res;

    }
};
