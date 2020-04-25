/**
 * Definition of Interval:
 * class Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    static bool mycomp(Interval &a, Interval &b){
        return a.start < b.start;
    }
    bool canAttendMeetings(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), mycomp);
        if(intervals.size() < 2) return true;
        for(int i = 0; i < intervals.size() - 1; i++){
            if(intervals[i].end > intervals[i+1].start) return false;
        }
        return true;
    }
};