#include <vector>
#include <algorithm>
using namespace std;


//普通01背包

int ans_01(vector<int> values, vector<int> widghts,float n)
{
	int len = values.size();
	vector<vector<int>> dp(len, vector<int>(n + 1, 0));

	for (int i = 1; i < len; ++i)
	{
		for (int j = n; j >= 0; --j)
		{
			if (j >= widghts[i])
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1] + values[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[len - 1][n];
}

//普通01背包优化
int ans_02(vector<int> values, vector<int> widghts, float n)
{
	int len = values.size();
	vector<int> dp(n + 1, 0);

	for (int i = 1; i < len; i++)
	{
		for (int j = n; j >= widghts[i]; --j)
		{
			dp[j] = max(dp[j - 1], dp[j] + values[i]);
		}
	}
	return dp[n];
}

//完全背包问题
int ans_03(vector<int> values, vector<int> widghts, float n)
{
	int len = values.size();
	vector<int> dp(n + 1, 0);

	for (int i = 1; i < len; ++i)
	{
		for (int j = widghts[i]; j <= n; ++j)
		{
			dp[j] = max(dp[j - 1], dp[j] + values[i]);
		}
	}
	return dp[n];
}