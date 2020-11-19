#pragma once
#include "IQuestion.h"
#include <vector>

using namespace std;
class Q_973 :
	public IQuestion
{
public:
	void Execute() override;

	vector<vector<int>> ans_01(vector<vector<int>>& points, int K);
};

