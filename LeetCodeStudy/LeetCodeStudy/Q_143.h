#pragma once
#include "IQuestion.h"
#include "Types.h"

using namespace std;

class Q_143 : public IQuestion
{
public:
	void Execute() override;
#pragma region �ⷨһ����O(N)�ռ䱣������˫ָ��
	void ans_01(ListNode* head);
#pragma endregion
};

