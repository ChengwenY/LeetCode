/**
给定一个字符串，逐个翻转字符串中的每个单词。

 

示例 1：

输入: "the sky is blue"
输出: "blue is sky the"
示例 2：

输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。

// 分析：首先整体翻转，找到收尾字符的index，然后逐个单词翻转，最后将单词中间的不符合空格清空，最后截取字符串
时间、空间复杂度O(N) 
写代码时注意 赋值与比较写的是否正确，== 和 = 是个坑 
*/
class Solution {
public:
    string reverseWords(string s) {
        // 整体翻转
        reverse(s.begin(), s.end());
        int len = s.size(), start = 0, end = len-1;
        while (start <= end && s[start]==' ') start++;
        while (end >=0 && s[end] == ' ') end--;
        if (start > end) return "";

        // //逐个单词翻转
        for (int strL = start; strL <= end;){
            while (s[strL] == ' ' && strL <= end) strL++; //找到单词开头字母index
            int r = strL; // 使用r变量来寻找单词结尾
            while (s[r] != ' ' && r <= end) r++; // 找到单词结尾index
            reverse(s.begin()+strL, s.begin()+r);
            strL = r;
        }

        //清空中间空格
        int tail = start;
        for (int i = start; i <= end; i++) {
            if (s[i] == ' ' && s[i-1] == ' ') continue;
            s[tail++] = s[i];
        }
        return s.substr(start, tail-start);
    }
};

