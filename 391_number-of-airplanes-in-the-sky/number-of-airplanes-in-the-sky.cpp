/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/number-of-airplanes-in-the-sky
@Language: C++
@Datetime: 16-08-09 17:20
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
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        priority_queue<int, vector<int>, greater<int>> pq;
        int size = airplanes.size();
        if (size <= 1) return size;
        int i, count=0;
        sort(airplanes.begin(), airplanes.end(), [](Interval a, Interval b) {return a.start < b.start;});
        pq.push(airplanes[0].end);
        count++;
        for (i=1; i<size; i++) {
            if (airplanes[i].start >= pq.top()) {
                pq.pop();
            } else {
                count++;
            }
            pq.push(airplanes[i].end);
        }
        return count;
    }
};