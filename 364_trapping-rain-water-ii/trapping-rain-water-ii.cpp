/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/trapping-rain-water-ii
@Language: C++
@Datetime: 15-09-26 18:15
*/

class Solution {
public:
    /**
     * @param heights: a matrix of integers
     * @return: an integer
     */
    struct Cell {
        int i;
        int j;
        int height;
    };

    /**
     * @param heights: a matrix of integers
     * @return: an integer
     */
    int trapRainWater(vector<vector<int>> &heights) {
        const int m = heights.size();
        const int n = heights[0].size();
        int trap = 0;
        vector<vector<bool>> is_visited(m, vector<bool>(n, false));

        // Use min heap to get the lowerest Cell.
        auto comp = [](const Cell& a, const Cell& b ) { return a.height > b.height; };
        priority_queue<Cell , vector<Cell>, decltype(comp)> heap(comp);

        // Put the Cells on the border into min heap.
        for (int i = 0; i < m; ++i) {
            heap.emplace(Cell{i, 0, heights[i][0]});
            heap.emplace(Cell{i, n - 1, heights[i][n - 1]});
        }
        for (int j = 0; j < n; ++j) {
            heap.emplace(Cell{0, j, heights[0][j]});
            heap.emplace(Cell{m - 1, j, heights[m - 1][j]});
        }

        // BFS with priority queue (min heap)
        while (!heap.empty()) {
            // Get the lowest Cell.
            Cell c = heap.top();
            heap.pop();
            is_visited[c.i][c.j] = true;

            // Up
            if (c.i + 1 < m && !is_visited[c.i + 1][c.j]) {
                is_visited[c.i + 1][c.j] = true;
                trap += max(0, c.height - heights[c.i + 1][c.j]); // Fill in the gap.
                heap.emplace(Cell{c.i + 1, c.j, max(c.height,
                                                    heights[c.i + 1][c.j])});
            }
            // Down
            if (c.i - 1 >= 0 && !is_visited[c.i - 1][c.j]) {
                is_visited[c.i - 1][c.j] = true;
                trap += max(0, c.height - heights[c.i - 1][c.j]); // Fill in the gap.
                heap.emplace(Cell{c.i - 1, c.j, max(c.height,
                                                    heights[c.i - 1][c.j])});
            }
            // Right
            if (c.j + 1 < n && !is_visited[c.i][c.j + 1]) {
                is_visited[c.i][c.j + 1] = true;
                trap += max(0, c.height - heights[c.i][c.j + 1]); // Fill in the gap.
                heap.emplace(Cell{c.i, c.j + 1, max(c.height,
                                                    heights[c.i][c.j + 1])});
            }
            // Left
            if (c.j - 1 >= 0 && !is_visited[c.i][c.j - 1]) {
                is_visited[c.i][c.j - 1] = true;
                trap += max(0, c.height - heights[c.i][c.j - 1]); // Fill in the gap.
                heap.emplace(Cell{c.i, c.j - 1, max(c.height,
                                                    heights[c.i][c.j - 1])});
            }
        }

        return trap;
    }
};
