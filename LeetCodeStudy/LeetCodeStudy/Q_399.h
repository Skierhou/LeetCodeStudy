#pragma once
#include "IQuestion.h"
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//给出方程式 A / B = k, 其中 A 和 B 均为用字符串表示的变量， k 是一个浮点型数字。根据已知方程式求解问题，并返回计算结果。如果结果不存在，则返回  - 1.0。
//
//输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。
//
//
//
//示例 1：
//
//输入：equations = [["a", "b"], ["b", "c"]], values = [2.0, 3.0], queries = [["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]]
//输出：[6.00000, 0.50000, -1.00000, 1.00000, -1.00000]
//解释：
//给定：a / b = 2.0, b / c = 3.0
//问题：a / c = ? , b / a = ? , a / e = ? , a / a = ? , x / x = ?
//返回：[6.0, 0.5, -1.0, 1.0, -1.0]
//示例 2：
//
//输入：equations = [["a", "b"], ["b", "c"], ["bc", "cd"]], values = [1.5, 2.5, 5.0], queries = [["a", "c"], ["c", "b"], ["bc", "cd"], ["cd", "bc"]]
//输出：[3.75000, 0.40000, 5.00000, 0.20000]
//示例 3：
//
//输入：equations = [["a", "b"]], values = [0.5], queries = [["a", "b"], ["b", "a"], ["a", "c"], ["x", "y"]]
//输出：[0.50000, 2.00000, -1.00000, -1.00000]
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/evaluate-division
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Q_399 : public IQuestion
{
public:
	void Execute() override;

	//题目解析： 如已知[a,b]，[b,c]，需要求得a c的关系，从a开始遍历所有相关解， 不是c则继续遍历， 过程中保存以及求过值的列表(避免死循环)
	//题目类似于 图形算法，由一个点依次计算其他多个点
	unordered_map<string, unordered_map<string, double>> graph;

#pragma region 解法一：DFS 
	vector<double> ans_01(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries);
	double ans_01_dfs(string a,string b,unordered_set<string> visited);
#pragma endregion

#pragma region 解法二：BFS
	vector<double> ans_02(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries);
#pragma endregion


};

