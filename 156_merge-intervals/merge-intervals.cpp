/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/merge-intervals
@Language: C++
@Datetime: 16-01-29 19:15
*/

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        int size = intervals.size();
        vector<Interval> result;
        if (size == 0) return result;
        if (size == 1) return intervals;
        int i;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){ return a.start < b.start;});
        result.push_back(intervals[0]);
        for (i=1; i<size; i++) {
            Interval &prev = result.back();
            if (intervals[i].start <= prev.end) {
                prev.end = max(intervals[i].end, prev.end);
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};