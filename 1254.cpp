/*
1254. Number of Closed Islands


Description:

Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

 

Example 1:

Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).

Example 2:

Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1

Example 3:

Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2

 

Constraints:

    1 <= grid.length, grid[0].length <= 100
    0 <= grid[i][j] <=1

*/

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int out = 0;
        vector<vector<bool>> checked(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 1; i < grid.size() - 1; i++) {
            for (int j = 1; j < grid[0].size() - 1; j++) {
                if (grid[i][j] == 1 || checked[i][j]) {
                    continue;
                }
                bool is_island = true;
                queue<pair<int, int>> search;
                search.push(pair<int, int>(i, j));
                while (!search.empty()) {
                    pair<int, int> cur = search.front();
                    search.pop();
                    if (checked[cur.first][cur.second]) {
                        continue;
                    }
                    checked[cur.first][cur.second] = true;
                    if (cur.first == 0 || cur.first == grid.size() - 1
                        || cur.second == 0 || cur.second == grid[0].size() - 1) {
                        is_island = false;
                    }
                    const vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                    for (int k = 0; k < moves.size(); k++) {
                        pair<int, int> new_pos = {cur.first + moves[k].first, cur.second + moves[k].second};
                        if (new_pos.first < 0 || new_pos.first >= grid.size() || 
                            new_pos.second < 0 || new_pos.second >= grid[0].size()) {
                            continue;
                        }
                        if (grid[new_pos.first][new_pos.second] == 1) {
                            continue;
                        }
                        if (checked[new_pos.first][new_pos.second]) {
                            continue;
                        }
                        search.push(new_pos);
                    }
                }
                if (is_island) {
                    out++;
                }
            }
        }
        return out;
    }
};
