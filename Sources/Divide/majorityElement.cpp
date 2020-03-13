/**
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2
*/
// 分治法 时间复杂度O(nlogn) 
//空间复杂度O（logn）。尽管分治算法没有直接分配额外的数组空间，但在递归的过程中使用了额外的栈空间。算法每次将数组从中间分成两部分，所以数组长度变为 1 之前需要进行 O(logn) 次递归，即空间复杂度为 O(logn)。

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return divide(nums, 0, nums.size()-1);
    }
    int divide(vector<int>& nums, int l, int r) {
        if (l == r) return nums[l];
        int mid = l + (r-l)/2;
        int leftMajor = divide(nums, l, mid), rightMajor = divide(nums, mid+1, r);
        if (leftMajor == rightMajor) return leftMajor;
        int leftCount = 0, rightCount = 0;
        for(int i = l; i <= r; i++) {
            if (nums[i] == leftMajor) {
                leftCount ++;
            } 
            if (nums[i] == rightMajor) {
                rightCount ++;
            }
        }
        return leftCount > rightCount ? leftMajor : rightMajor;
    }
};
// 哈希表 时间复杂度O(n) 空间复杂度O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        int majority = 0, cnt = 0;
        for (int num: nums) {
            ++counts[num];
            if (counts[num] > cnt) {
                majority = num;
                cnt = counts[num];
            }
        }
        return majority;
    }
};
