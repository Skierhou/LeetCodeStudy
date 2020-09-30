#pragma once
#include "IQuestion.h"
#include <vector>

using namespace std;

//给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
//
//
//
//示例 1:
//
//输入: [2, 3, -2, 4]
//输出 : 6
//解释 : 子数组[2, 3] 有最大乘积 6。
//示例 2 :
//
//	输入 : [-2, 0, -1]
//	输出 : 0
//	解释 : 结果不能为 2, 因为[-2, -1] 不是子数组。
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/maximum-product-subarray
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Q_152: public IQuestion
{
public:
	void Execute() override;

	//暴力解
	int ans_01(vector<int>& nums);
	//动态规划+空间节省(保存两个dp分别是max，min，f[n] = max(fmax[n-1]*nums[n], fmin[n-1]*nums[n], nums[n]);
	int ans_02(vector<int>& nums);
};

