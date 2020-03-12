/**
给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对。

你需要返回给定数组中的重要翻转对的数量。

示例 1:

输入: [1,3,2,3,1]
输出: 2
示例 2:

输入: [2,4,3,5,1]
输出: 3
注意:

给定数组的长度不会超过50000。
输入数组中的所有数字都在32位整数的表示范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

题解： 归并排序的典型应用，
时间复杂度：O（nlogn）
空间复杂度：O (n)
*/
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int>temp(nums.size());
        return mergeSort(nums, temp,0, nums.size()-1);
    }

    int mergeSort(vector<int> &nums,vector<int> &temp,int s, int e) {
        if (s>=e) return 0;
        int mid = s + (e-s)/2;
        //左右分别计算翻转对数量
        int lCount = mergeSort(nums, temp ,s, mid), rCount = mergeSort(nums, temp ,mid+1, e);
        int cnt = lCount + rCount;
        int i = s, j = mid + 1;
        while (i <= mid && j <= e) {
            if (nums[i] > 2L * nums[j]) {
                cnt += mid - i + 1; // i~mid 之间的数字都> 2*nums[j] 所以加上mid-i+1
                j++;
            } else i++;
        }
        myMerge(nums, temp, s, mid, e);
        return cnt;
    }
    void myMerge(vector<int> &nums, vector<int> &temp, int s, int mid ,int e) {
        int i = s, k = s, j = mid+1;
        while (i <= mid && j <= e) {
            temp[k++] = nums[i] <= nums[j] ? nums[i++] : nums[j++];
        }
        while (i <= mid) temp[k++] = nums[i++];
        while (j <= e) temp[k++] = nums[j++];
        for (int p = s; p <= e; p++) {
            nums[p] = temp[p];
        }
    }
};
