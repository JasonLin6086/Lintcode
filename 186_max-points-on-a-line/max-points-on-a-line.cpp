/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/max-points-on-a-line
@Language: C++
@Datetime: 16-01-29 18:42
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    /**
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        // Write your code here
        int size = points.size();
        if (size <= 2) return size;
        int i, j, maxV;

        for (i=0; i<size; i++) {
            unordered_map<double, int> hash;
            int vertical=1, dup=0, local=0;
            for (j=i+1; j<size; j++) {
                if (points[j].x == points[i].x) {
                    if (points[j].y == points[i].y) {
                        dup++;
                    } else {
                        vertical++;
                    }
                } else {
                    double slope = (points[j].y - points[i].y) * 1.0 / (points[j].x - points[i].x);
                    hash[slope]==0 ? hash[slope]=2 : hash[slope]++;
                    local = max(local, hash[slope]);
                }
            }
            local = max(vertical, local) + dup;
            maxV = max(local, maxV);
        }
        return maxV;
    }
};