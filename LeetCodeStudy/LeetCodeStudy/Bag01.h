#include "IQuestion.h"
#include <vector>

using namespace std;

class Bag01 : public IQuestion
{
public:
	void Execute() override;

	int ans_01(vector<int> wVec, vector<int> vVec, int bagWeight);
	int ans_02(vector<int> wVec, vector<int> vVec, int bagWeight);
	int ans_03(vector<int> wVec, vector<int> vVec, int bagWeight);
	int ans_04(vector<int> wVec, vector<int> vVec, vector<int> pVec, int bagWeight);
	int ans_05(vector<int> wVec, vector<int> vVec, vector<int> pVec, int bagWeight);
	int ans_06(vector<int> wVec, vector<int> vVec, vector<int> pVec, int bagWeight);
	int ans_07(vector<int> wVec, vector<int> vVec, vector<int> gVec, int wLimit, int gLimit);
};
