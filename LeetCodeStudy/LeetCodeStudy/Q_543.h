﻿#pragma once

#include "Types.h"
#include "IQuestion.h"
using namespace std;


//二叉树的直径：给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。
//示例:
//给定二叉树
//
//     1
//    / \
//   2   3
//  / \
// 4   5
//返回 3, 它的长度是路径[4, 2, 1, 3] 或者 [5, 2, 1, 3]。
//
//注意：两结点之间的路径长度是以它们之间边的数目表示。
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/word-break
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Q_543 : public IQuestion
{
public:

	//ans = 1开始是因为，一条路径的长度=节点数-1，求路径长度相当于求经过一个节点数最大值-1
	//计算节点深度：max(l,r)+1，计算当前节点最大路径数：l+r+1
	int ans_01(TreeNode* root);
	int depth(TreeNode* root);
	void Execute() override;

	int ans;
};

