/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
//conference rooms maximum number of overlapping rooms 
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<int>starts, ends;
        for(const auto&i : intervals)
        {
        starts.emplace_back(i.start);
        ends.emplace_back(i.end);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int min_rooms = 0;
        int cnt_rooms = 0;
int s = 0, e = 0;
        while(s<starts.size())
        {
        //start shhould be less then the ending time 
          if (starts[s] < ends[e]) {
                ++cnt_rooms;  
                
                min_rooms = max(min_rooms, cnt_rooms);
                ++s;
            } else {
                --cnt_rooms;  
                ++e;
            }
        }
        return min_rooms;
    }
};
