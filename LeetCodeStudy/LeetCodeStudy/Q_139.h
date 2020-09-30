#pragma once
#include "IQuestion.h"
#include <string>
#include <vector>
using namespace std;

//给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
//
//说明：
//
//拆分时可以重复使用字典中的单词。
//你可以假设字典中没有重复的单词。
//示例 1：
//
//输入 : s = "leetcode", wordDict = ["leet", "code"]
//输出 : true
//解释 : 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
//示例 2：
//
//输入 : s = "applepenapple", wordDict = ["apple", "pen"]
//输出 : true
//解释 : 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
//注意你可以重复使用字典中的单词。
//示例 3：
//
//输入 : s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
//输出 : false
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/word-break
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Q_139:public IQuestion
{
public:
	void Execute() override;

	//暴力递归求解，时间复杂度O(n^2)
	//思路：每次循环字符串只找最前面列表里存在的子项
	bool ans_01(string s, vector<string>& wordDict);

	//动态规划求解：时间复杂度O(n^2)
	//j<i的情况下，dp[i]=dp[j] && check(substr(j,i))
	bool ans_02(string s, vector<string>& wordDict);
};

