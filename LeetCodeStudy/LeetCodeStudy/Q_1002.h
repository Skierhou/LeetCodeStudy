#pragma once
#include "IQuestion.h"
#include <vector>
#include <string>

using namespace std;

//��������Сд��ĸ��ɵ��ַ������� A�������б��е�ÿ���ַ����ж���ʾ��ȫ���ַ��������ظ��ַ�����ɵ��б����磬���һ���ַ���ÿ���ַ����г��� 3 �Σ������� 4 �Σ�����Ҫ�����մ��а������ַ� 3 �Ρ�
//
//����԰�����˳�򷵻ش𰸡�
//
//
//
//ʾ�� 1��
//
//���룺["bella", "label", "roller"]
//�����["e", "l", "l"]
//ʾ�� 2��
//
//���룺["cool", "lock", "cook"]
//�����["c", "o"]
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/find-common-characters
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

class Q_1002:public IQuestion
{
public:
	void Execute() override;

	vector<string> ans_01(vector<string>& A);
};

