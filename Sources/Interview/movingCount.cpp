/**
    地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
    一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），
    也不能进入行坐标和列坐标的数位之和大于k的格子。
    例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

     
    示例 1：

    输入：m = 2, n = 3, k = 1
    输出：3


分析：典型的搜索算法，可以使用bfs或dfs来解决。参考岛屿问题。由0，0开始深度遍历每一个结点，遇到不符合条件的结点终止递归。
时间、空间复杂度O(mn)
*/
class Solution {
public:
    int getSum(int x) {
        int sum = 0;
        while (x) {
            sum += x%10;
            x = x /10;
        }
        return sum;
    }
    int movingCount(int m, int n, int k) {
        int ans = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        ans += dfs(m, n, 0, 0, k, visited);
        return ans;
    }

    int dfs(int m, int n, int i, int j, int k, vector<vector<int>> &visited) {
        if(i < 0 || i >= m || j <0 || j >= n || (getSum(i) + getSum(j)) > k || visited[i][j]) return 0;
        visited[i][j] = 1;
        int x = dfs(m, n, i+1, j, k, visited), y = dfs(m, n, i, j+1, k, visited);
        return 1 + x + y;
    } 
};
