#pragma once
#include "IQuestion.h"
#include <vector>
#include <string>
using namespace std;

//n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
//
//
//
//上图为 8 皇后问题的一种解法。
//
//给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
//
//每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/n-queens
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class NQueen: public IQuestion
{
public:
	void Execute() override;

#pragma region 解法一
    vector<vector<string>> ans_01(int n);
    void ans_01_backtrack(vector<vector<char>> vec, int hash, int layer, int n, vector<vector<string>>& res);
    bool ans_01_check(vector<vector<char>> vec, int i, int layer, int n);
#pragma endregion

#pragma region 解法一相对优化版
    vector<vector<string>> ans_02(int n);
    void ans_02_backtrack(int col,int bevel1,int bevel2,int layer,int n, vector<int>& vec, vector<vector<string>>& res);
    vector<string> ans_02_generated(vector<int> vec);
#pragma endregion
};

