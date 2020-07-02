/**
给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

示例:

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

    滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

*/

//暴力法，依次遍历每个窗口 时间复杂度O(nK) 空间复杂度O(1)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;        
        if (nums.size() == 0) return res;
        for (int i = 0; i <= nums.size()-k; i++) {
            int maxN = nums[i];
            for (int j = i+1; j < i+k; j++) {
                maxN = max(maxN, nums[j]);
            }
            res.push_back(maxN);
        }
        return res;
    }

//时间复杂度 O(N) 空间复杂度O（k）队列最大存储k个元素 

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        if (n == 0) return res;
        deque<int> dq;
        for (int i = 0; i < n; i++) {
            // 保持队列单调递增 将i加到尾部并去掉小于它的值
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            //判断头部元素是否已经超出窗口 
            if (dq.front() == i-k) {
                dq.pop_front();
            }
            if (i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};

