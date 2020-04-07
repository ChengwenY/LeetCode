/**
给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。

不占用额外内存空间能否做到？

 

示例 1:

给定 matrix = 
[
    [1,2,3],
    [4,5,6],
    [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
    [7,4,1],
    [8,5,2],
    [9,6,3]
]

// 分析： 2种解法
1、暴力法 
使用额外数组，依次将第一列、第二列数填入新数组。时间复杂度和空间复杂度均为O(n^2)
2、翻转法
先水平翻转再沿主对角线翻转即可得到旋转矩阵
注意for循环的条件
*/
class Solution {
public:
    // 翻转法
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < n; j++) {
                swap(matrix[i][j], matrix[n-1-i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    // 暴力法
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> res;
        for (int c = 0; c < n; c++) {
            vector<int> subRes;
            for (int r = n-1; r >= 0; r--) {
                subRes.push_back(matrix[r][c]);
            }
            res.push_back(subRes);
        }
        matrix = res;
    }
};
