class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //picking interval with earliest end time 
        //intervals = [[1,2], [2,4], [1,4]]

        //[1,4] neds to eb removed 

    
    //[1,2], [1,4], [2, 4]

        sort(intervals.begin(), intervals.end(), [](const vector<int>&a, const vector<int>&b)
        {
            return a[1]<b[1];
        });
        int count = 1;
        //curr_interval = [1,2]
        
        vector<int>curr_interval(intervals[0]);
        int n = intervals.size();
        int i=1;
        //i=2
        while(i<n)
        {
            //curr_intervl[1] = 2
            //intervals[2][0] = 2
            //2<=1 No
            //2<=2 Yes
            //next intervak start is after current end
            if(curr_interval[1]<=intervals[i][0])
            {
                //count = 2
                ++count;
                //curr_interval = [2,4]
                curr_interval = intervals[i];
            }
            ++i;
        }
        //remaining needs to removed
        //n=3 count = 2 ;
        // 3-2 = 1
        //1 overllapping intervals is the reuslt 
        return n-count;

    }
};
