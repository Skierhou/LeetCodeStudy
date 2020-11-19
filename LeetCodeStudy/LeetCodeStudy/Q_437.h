#pragma once
#include "IQuestion.h"
#include "Types.h"
#include <unordered_map>

using namespace std;

//����һ��������������ÿ����㶼�����һ������ֵ��
//
//�ҳ�·���͵��ڸ�����ֵ��·��������
//
//·������Ҫ�Ӹ��ڵ㿪ʼ��Ҳ����Ҫ��Ҷ�ӽڵ����������·��������������µģ�ֻ�ܴӸ��ڵ㵽�ӽڵ㣩��
//
//������������1000���ڵ㣬�ҽڵ���ֵ��Χ��[-1000000, 1000000] ��������
//
//ʾ����
//
//root = [10, 5, -3, 3, 2, null, 11, 3, -2, null, 1], sum = 8
//
//10
/// \
//5 - 3
/// \    \
//3   2   11
/// \   \
//3 - 2   1
//
//���� 3���͵��� 8 ��·����:
//
//1.  5 -> 3
//2.  5 -> 2 -> 1
//3. - 3 -> 11
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/path-sum-iii
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

class Q_437 : public IQuestion
{
public:
	void Execute() override;

	int res = 0;
#pragma region �ⷨһ��DFS
	int ans_01(TreeNode* root, int sum);
	void ans_01_dfs(TreeNode* root, int curr, int sum, bool bNormal = false);
#pragma endregion

#pragma region �ⷨ����ǰ׺�͵ݹ���� O(N)
	int ans_02(TreeNode* root, int sum);
	int ans_02_loop(TreeNode* node, unordered_map<int, int> prefixSumCount, int target, int currSum);
#pragma endregion


};

