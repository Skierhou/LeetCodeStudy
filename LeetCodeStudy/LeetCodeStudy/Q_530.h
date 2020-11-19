#pragma once
#include "Types.h"
#include "IQuestion.h"

using namespace std;

//����һ�����нڵ�Ϊ�Ǹ�ֵ�Ķ�����������������������������ڵ�Ĳ�ľ���ֵ����Сֵ��
//
//
//ʾ����
//
//���룺
//
//	1
//	 \
//	  3
//	 /
//	2
//
//�����
//1
//
//���ͣ�
//��С���Բ�Ϊ 1������ 2 �� 1 �Ĳ�ľ���ֵΪ 1������ 2 �� 3����
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/minimum-absolute-difference-in-bst
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

class Q_530 : public IQuestion
{
public:
	void Execute() override;

#pragma region ���������⣺�������������������������������ģ�
	int ans_01(TreeNode* root);
	void ans_01_dfs(TreeNode* root, int& res, int& pre);
#pragma endregion

};

