/**
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

 

示例：

输入：n = 3
输出：[
       "((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"
     ]

分析： 典型的回溯+剪枝算, 判断剪枝条件 r>l || l > n || r > n 时剪枝，当s.size()==2*n 时s即为符合条件的字符串。

此题还可用广度优先遍历和动态规划求解
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res, 0, 0, "", n);
        return res;
    }

    void dfs(vector<string> &res, int l, int r, string s,int n) {
        if (r > l || l > n) return;
        if (s.size() == 2*n) {
            res.push_back(s);
            return;
        }
        dfs(res, l+1, r,  s + '(', n);
        dfs(res, l, r+1,  s + ')', n);
    }
};

//动态规划 
/**当我们清楚所有 i<n 时括号的可能生成排列后，对与 i=n 的情况，我们考虑整个括号排列中最左边的括号。
它一定是一个左括号，那么它可以和它对应的右括号组成一组完整的括号 "( )"，我们认为这一组是相比 n-1 增加进来的括号。

那么，剩下 n-1 组括号有可能在哪呢？

【这里是重点，请着重理解】

剩下的括号要么在这一组新增的括号内部，要么在这一组新增括号的外部（右侧）。

既然知道了 i<n 的情况，那我们就可以对所有情况进行遍历：

"(" + 【i=p时所有括号的排列组合】 + ")" + 【i=q时所有括号的排列组合】

其中 p + q = n-1，且 p q 均为非负整数。

事实上，当上述 p 从 0 取到 n-1，q 从 n-1 取到 0 后，所有情况就遍历完了。

注：上述遍历是没有重复情况出现的，即当 (p1,q1)≠(p2,q2) 时，按上述方式取的括号组合一定不同。*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {};
        vector<vector<string>> dp(n+1, vector<string>());
        dp[0].push_back("");
        for (int i = 1; i <= n; i++) {
            for (int k = 0; k < i; k++) {
                for (string s1: dp[k]) {
                    for (string s2 : dp[i-k-1]) {
                        dp[i].push_back("("+s1+")"+s2);
                    }
                }
            }
        }
        return dp[n];
    }
};
