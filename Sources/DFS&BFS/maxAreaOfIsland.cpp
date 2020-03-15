/**
给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向 (水平或垂直) 的 1 (代表土地) 构成的组合。你可以假设二维矩阵的四个边缘都被水包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)

典型的岛屿四向连通问题， 采用dfs算法
时间复杂度： O(R*C) 每个元素最多遍历一次，所以时间复杂度即为二维数组的元素数量。
空间复杂度：O(R*C) 栈最大深度可能是整个数组的大小
*/
class Solution {
private: 
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0, row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    maxArea = max(maxArea, dfs(grid, i, j, row, col, area));
                }
            }
        }
        return maxArea;
    }
    int dfs(vector<vector<int>> &grid, int row, int col, int maxRow, int maxCol, int &res) {
        if (grid[row][col] != 1) return 0;
        grid[row][col] = 0;
        res ++;
        for (int k = 0; k < 4; k++) {
            int newRow = row + dy[k], newCol = col + dx[k];
            if (isInIsland(maxRow, maxCol,newRow, newCol))
            {
                dfs(grid, newRow, newCol, maxRow, maxCol,res);
            }
        }
        return res;
    }
    bool isInIsland(int maxRow, int maxCol,int row, int col) {
        return row >= 0 && row < maxRow && col >= 0 && col < maxCol;
    }
};
