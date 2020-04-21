/**
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

示例 1:

输入:
11110
11010
11000
00000
输出: 1
示例 2:

输入:
11000
11000
00100
00011
输出: 3
解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。

*/
//分析 典型回溯算法 dfs 确定一个岛屿后通过dfs将附近的1都置位0 时间复杂度O(MN) MN是数组行列 空间复杂度O(MN)
class Solution {
    private: 
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int m = grid.size(), n = grid[0].size(), ans = 0;
        if (m == 0) return 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, m, n);
                    ans ++;
                }   
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>> &grid,int i, int j, int m, int n) {
        if (grid[i][j] == '0') return;
        grid[i][j] = '0';

        for (int k = 0; k < 4; k++) {
            int newX = i + dx[k], newY = j + dy[k];
            if (isValid(newX, newY, m, n)) {
                dfs(grid ,newX, newY, m, n);
            }
        }
 
    }
    bool isValid(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >=0 && j < n;
    }
};
