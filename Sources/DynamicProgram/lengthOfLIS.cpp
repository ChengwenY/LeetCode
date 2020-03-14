// 时间复杂度： O(n^2)
// 空间复杂度： O(n);
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size(), maxLen = 1; 
        if (len == 0) return 0;
        vector<int> dp(len, 1);
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < i; j++) { // 遍历i之前的元素
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1); // 以i为结尾的上升子序列最大长度
                }
            }
            maxLen = max(dp[i], maxLen);
        }
        return maxLen;
    }
};
/** 贪心+二分法
    依然是着眼于一个上升子序列的结尾的元素；
    如果已经得到的上升子序列的结尾的数越小，遍历的时候后面接上一个数，就会有更大的可能性构成一个更长的上升子序列；
    既然结尾越小越好，我们可以记录在长度固定的情况下，结尾最小的那个元素的数值，这样定义也是为了方便得到「状态转移方程」。
    时间复杂度： O（nlogn）
    空间复杂度： O (n)
    https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-dong-tai-gui-hua-2/
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        vector<int> tail;
        tail.push_back(nums[0]);
        int end = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > tail[end]) { // 以i为结尾可以构成一个最大长度的序列 
                tail.push_back(nums[i]);    
                end++;
            } else { 
                int r = end, l = 0;
                while (l < r) {
                    int mid = (l + r) >> 1;
                    if (tail[mid] < nums[i]) {
                        l = mid+1;
                    } else {
                        r = mid;
                    }
                }
                tail[l] = nums[i];
            }
        }
        return end+1;
    }
};
