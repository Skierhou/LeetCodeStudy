#pragma once
#include "IQuestion.h"
#include <vector>
using namespace std;

class Q_31 :
	public IQuestion
{
public:
	void Execute() override;

	void nextPermutation(vector<int>& nums);
};

