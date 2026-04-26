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

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        ranges::sort(intervals, {}, &Interval::start);
        auto conflict = ranges::adjacent_find(intervals, [](const auto&prev, const auto&curr)
        {
return curr.start<prev.end;
        });
        return conflict == intervals.end();
    }
};
