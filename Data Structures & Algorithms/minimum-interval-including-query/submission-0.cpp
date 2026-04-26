class Solution {
public:
// Input: intervals = [[1,3],[2,3],[3,7],[6,6]], queries = [2,3,1,7,6,8]

// Output: [2,2,3,5,1,-1]
// Explanation:

// Query = 2: The interval [2,3] is the smallest one containing 2, it's length is 2.
// Query = 3: The interval [2,3] is the smallest one containing 3, it's length is 2.
// Query = 1: The interval [1,3] is the smallest one containing 1, it's length is 3.
// Query = 7: The interval [3,7] is the smallest one containing 7, it's length is 5.
// Query = 6: The interval [6,6] is the smallest one containing 6, it's length is 1.
// Query = 8: There is no interval containing 8.
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        //[[1,3],[2,3],[3,7],[6,6]],
        sort(intervals.begin(), intervals.end());
vector<int>res(queries.size());

multimap<int, int>qm;
//{2, 0}, {3, 1}, {1, 2}, {7, 3}, {6, 4}, {8, 5}
for(int i=0; i<queries.size(); i++)qm.insert({queries[i], i});

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>minHeap;
int i=0;

for(pair<int, int>qi : qm)
{
    while(i<intervals.size() && intervals[i][0]<=qi.first)
    {
        minHeap.push({intervals[i][1]-intervals[i][0]+1 , intervals[i][1]});
        i++;
    }
    while(!minHeap.empty()&&minHeap.top().second<qi.first)
    minHeap.pop();

    if(minHeap.empty())
    res[qi.second] = -1;
    else
    res[qi.second] = minHeap.top().first;
}
return res;
    }
};
