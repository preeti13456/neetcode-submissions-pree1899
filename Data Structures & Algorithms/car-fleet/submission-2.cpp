class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //distTime = 4
        vector<pair<int, double>>distTime(speed.size());
//        Input: target = 10, position = [4,1,0,7], speed = [2,2,1,1]

// Output: 3
for(int i=0; i<position.size(); i++)
{
    //[[6, 3], [9, 4], [10, 10], [3, 3]]
    distTime[i] = {target-position[i], ((target-position[i])/(1.0*speed[i]))};
}
//[[3,3], [6,3], [9, 4], [10,10]];
sort(distTime.begin(), distTime.end());

int res = 1;
for(int i=1; i<distTime.size();i++)
{
    //3 >= 3
    //3>=4 false
//4>=10 false
//10>=3 true
    if(distTime[i-1].second >= distTime[i].second)
    {
        //10=3
     distTime[i].second = distTime[i-1].second   ;
    }
    else
    {
        //res = 3
        res++;
    }
}
return res;
    }
};
