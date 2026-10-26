/*
3619. Count Islands With Total Value Divisible by K


Description:

You are given an m x n matrix grid and a positive integer k. An island is a group of positive integers (representing land) that are 4-directionally connected (horizontally or vertically).

The total value of an island is the sum of the values of all cells in the island.

Return the number of islands with a total value divisible by k.

 

Example 1:

Input: grid = [[0,2,1,0,0],[0,5,0,0,5],[0,0,1,0,0],[0,1,4,7,0],[0,2,0,0,8]], k = 5

Output: 2

Explanation:

The grid contains four islands. The islands highlighted in blue have a total value that is divisible by 5, while the islands highlighted in red do not.

Example 2:

Input: grid = [[3,0,3,0], [0,3,0,3], [3,0,3,0]], k = 3

Output: 6

Explanation:

The grid contains six islands, each with a total value that is divisible by 3.

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 1000
    1 <= m * n <= 105
    0 <= grid[i][j] <= 106
    1 <= k <= 106


*/

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int out = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 0) {
                    continue;
                }
                int size = 0;
                queue<pair<int, int>> search;
                search.push(pair<int, int>(i, j));
                while (!search.empty()) {
                    pair<int, int> cur = search.front();
                    search.pop();
                    if (grid[cur.first][cur.second] == 0) {
                        continue;
                    }
                    size += grid[cur.first][cur.second] % k;
                    grid[cur.first][cur.second] = 0;
                    vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                    for (int m = 0; m < moves.size(); m++) {
                        pair<int, int> new_pos = {cur.first + moves[m].first, cur.second + moves[m].second};
                        if (new_pos.first < 0 || new_pos.first >= grid.size()) {
                            continue;
                        }
                        if (new_pos.second < 0 || new_pos.second >= grid[0].size()) {
                            continue;
                        }
                        if (grid[new_pos.first][new_pos.second] == 0) {
                            continue;
                        }
                        search.push(new_pos);
                    }
                }
                if (size % k == 0) {
                    out++;
                }
            }
        }
        return out;
    }
};
