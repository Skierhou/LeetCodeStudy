#pragma once
#include "IQuestion.h"
#include "Types.h"

using namespace std;

class Q_143 : public IQuestion
{
public:
	void Execute() override;
#pragma region 解法一：用O(N)空间保存链表，双指针
	void ans_01(ListNode* head);
#pragma endregion
};

