class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //picking interval with earliest end time 
        //intervals = [[1,2], [2,4], [1,4]]

        //[1,4] neds to eb removed 

        sort(intervals.begin(), intervals.end(), [](const vector<int>&a, const vector<int>&b)
        {
            return a[1]<b[1];
        });
        int count = 1;
        vector<int>curr_interval(intervals[0]);
        int n = intervals.size();
        int i=1;
        while(i<n)
        {
            if(curr_interval[1]<=intervals[i][0])
            {
                ++count;
                curr_interval = intervals[i];
            }
            ++i;
        }
        return n-count;

    }
};
