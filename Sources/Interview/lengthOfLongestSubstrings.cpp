/**
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/
//分析：
//滑动窗口 窗口内的字符串为无重复子串，令k为窗口左侧index 遍历字符串 另i为待入窗口的index，比较s[i]在窗口[k, j) 区间是否有重复值，如果有重复值记该值index为j，i-j即为 以j为结尾的无重复子串窗口的长度，与当前max比较，将窗口右移，滑动结束后需要与maxL比较长度。
//时间复杂度O(n^2) 空间O(1);

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        int maxL = 1, k = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = k; j < i; j++) {
                if (s[i] == s[j]) {
                    maxL = max(maxL, i-j);
                    k = j+1;
                }
            }
            //窗口滑动结束后，该窗口可能是新的最长无重复子串，所以将当前窗口长度与maxLength比较大小。
            maxL = max(maxL, i-k+1);
        }
        return maxL;
    }
};

// 优化 O（n）
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        unordered_map<char,int> map;
        int maxL = 0, start = 0;
        for (int i = 0; i < s.size(); i++) {
            while (map.find(s[i]) != map.end()) {
                map.erase(s[start++]); //从start开始移除[start,i) 窗口数据
            }
            map[s[i]] = i;
            maxL = max(maxL, i-start+1);
        }
        return maxL;
    }
};