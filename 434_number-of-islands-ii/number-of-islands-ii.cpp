/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/number-of-islands-ii
@Language: C++
@Datetime: 15-10-01 17:27
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
     * @param n an integer
     * @param m an integer
     * @param operators an array of point
     * @return an integer array
     */
    vector<int> numIslands2(int n, int m, vector<Point>& operators) {
        // Write your code here
        unordered_map<int, int> father;
        vector<int> res;
        int cnt = 0;
        const int dx[] = {0, 1, 0, -1};
        const int dy[] = {1, 0, -1, 0};
        for (auto &op : operators) {
            int p = op.x * m + op.y;
            int fp = findFather(father, p);
            if (fp == p) ++cnt;
            for (int i = 0; i < 4; ++i) {
                int xx = op.x + dx[i], yy = op.y + dy[i];
                if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
                int q = (op.x + dx[i]) * m + op.y + dy[i];
                if (father.find(q) != father.end()) {
                    int fq = findFather(father, q);
                    if (fp != fq) {
                        --cnt;
                        father[fq] = fp;
                    }
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
private:
    int findFather(unordered_map<int, int> &father, int x) {
        if (father.find(x) == father.end()) {
            father[x] = x;
            return x;
        }
        int res = x, tmp;
        while (res != father[res]) {
            res = father[res];
        }
        while (x != father[x]) {
            tmp = father[x];
            father[x] = res;
            x = tmp;
        }
        return x;
    }
};
