#include "Bag01.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


void Bag01::Execute()
{

}

/*
1.特点：每种物品只有一件，只需要选择放或不放
推导公式：前i件物品的最大价值=max(前i-1件物品最大价值(不放i物品),放i物品)
--->定义f[i][j]，保存的是选择第i个物品时背包容量剩余j时的最大价值
可以求得：f[i][j] = max(f[i-1][j],f[i-1][j-w[i]]+v[i])
*/
int Bag01::ans_01(vector<int> wVec, vector<int> vVec, int bagWeight)
{
	int n = wVec.size() - 1;
	vector<vector<int>> f(wVec.size(), vector<int>(bagWeight + 1, 0));

	int j = bagWeight;
	for (int i = 1; i <= n; i++)
	{
		for (int j = bagWeight; j >= 0; j--)
		{
			if (j >= wVec[i])
				f[i][j] = max(f[i - 1][j], f[i - 1][j - wVec[i]] + vVec[i]);
			else
				f[i][j] = f[i - 1][j];
		}
	}
	return f[n][bagWeight];
}

/*
2.第一个解法时间上为O(n*V)，空间O(n*V)可以优化至O(n)，使用一维数组
现阶段需要解决的问题：怎么将二维数组转换成一维数组?
解析：i从1-n，每次判断f[i][j]时依据由f[i-1][1...j]决定，因此每次判断只需要使用上一次计算的结果
*/
int Bag01::ans_02(vector<int> wVec, vector<int> vVec, int bagWeight)
{
	int n = wVec.size() - 1;
	vector<int> f(bagWeight + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		for (int j = bagWeight; j >= wVec[i]; j--)
		{
			f[j] = max(f[j], f[j - wVec[i]] + vVec[i]);
		}
	}
	return f[bagWeight];
}

/* 二.完全背包问题
题目：有N种物品和一个容量为V的背包，每种物品都有无限件可用。第i种物品的费用是w[i]，价值是v[i]。求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。
*/

/*
1.首先需要考虑的是01背包为什么j倒序从V...0，为了确保每次计算结果都由j-w[i]来决定，而j-w[i]是绝无选择过第i个物体的一种选择
而完全背包问题，不需要考虑j-w[i]是否有选择过第i个物体，因此j需要正序从0...V
*/
int Bag01::ans_03(vector<int> wVec, vector<int> vVec, int bagWeight)
{
	int n = wVec.size() - 1;
	vector<int> f(bagWeight + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		for (int j = wVec[i]; j <= bagWeight; j++)
		{
			f[j] = max(f[j], f[j - wVec[i]] + vVec[i]);
		}
	}
	return f[bagWeight];
}

/* 三.多重背包问题
题目：有N种物品和一个容量为V的背包。第i种物品最多有p[i]件可用，每件费用是w[i]，价值是v[i]。
求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。
*/

/*
1.将多重选择转换成01背包求解，问：如何转换成01背包？将数量平铺下来就是一个一维数组
时间复杂度O(N*V*ΣP[i])
*/
int Bag01::ans_04(vector<int> wVec, vector<int> vVec, vector<int> pVec, int bagWeight)
{
	int n = wVec.size() - 1;
	vector<int> f(bagWeight + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		int num = min(pVec[i], bagWeight / wVec[i]);
		while (num > 0)
		{
			--num;
			for (int j = bagWeight; j >= wVec[i]; j--)
			{
				f[j] = max(f[j], f[j - wVec[i]] + vVec[i]);
			}
		}
	}
	return f[bagWeight];
}

/*
2.时间上优化，使用二进制方式优化重复物体的迭代，k=1..2..4..2^k，
时间复杂度O(N*V*Σlog(P[i]))
*/
int Bag01::ans_05(vector<int> wVec, vector<int> vVec, vector<int> pVec, int bagWeight)
{
	int n = wVec.size() - 1;
	vector<int> f(bagWeight + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		int num = min(pVec[i], bagWeight / wVec[i]);
		for (int k = 1; num > 0; k <<= 1)
		{
			if (k > num) k = num;
			num -= k;
			for (int j = bagWeight; j >= wVec[i] * k; j--)
			{
				f[j] = max(f[j], f[j - wVec[i] * k] + vVec[i] * k);
			}
		}
	}
	return f[bagWeight];
}

/*四.混合背包问题
1.将01背包与完全背包以及多重背包混合成一个题目，即：1.只能取1次的物品，2.能取无数次的物品，3.能取次数有上限的物品
*/

/*
1.先判断01背包与完全背包的混合，只需要拆分成正序循环以及倒序循环即可，只取1次的物品倒序，无限取的物品正序
再加入能取次数上限的物品，将其归入01背包范围即可(相当于多存几个物品的数组)
例：p[i] <= 0 时 ：可以无限取
*/
int Bag01::ans_06(vector<int> wVec, vector<int> vVec, vector<int> pVec, int bagWeight)
{
	int n = wVec.size() - 1;
	vector<int> f(bagWeight + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		if (pVec[i] <= 0)
		{
			for (int j = 0; j <= bagWeight; j++)
			{
				f[j] = max(f[j], f[j - wVec[i]] + vVec[i]);
			}
		}
		else
		{
			int num = min(pVec[i], bagWeight / wVec[i]);
			for (int k = 1; num > 0; k <<= 1)
			{
				if (k > num) k = num;
				num -= k;
				for (int j = bagWeight; j > wVec[i] * k; j--)
				{
					f[j] = max(f[j], f[j - wVec[i] * k] + vVec[i] * k);
				}
			}
		}
	}
	return f[bagWeight];
}

/*五.二维费用背包问题
二维费用的背包问题是指：对于每件物品，具有两种不同的费用；选择这件物品必须同时付出这两种代价；对于每种代价都有一个可付出的最大值（背包容量）。
问怎样选择物品可以得到最大的价值。设这两种代价分别为代价1和代价2，第i件物品所需的两种代价分别为w[i]和g[i]。两种代价可付出的最大值（两种背包容量）分别为V和T。物品的价值为v[i]。
*/

/*
1.多维费用解法与一维类似，扩大空间，思路一致
*/
int Bag01::ans_07(vector<int> wVec, vector<int> vVec, vector<int> gVec, int wLimit, int gLimit)
{
	int n = wVec.size() - 1;
	vector<vector<int>> f(wLimit + 1, vector<int>(gLimit + 1, 0));

	for (int i = 1; i <= n; ++i)
	{
		for (int j = wLimit; j >= wVec[i]; --j)
		{
			for (int g = gLimit; g >= gVec[i]; --g)
			{
				f[j][g] = max(f[j][g], f[j - wVec[i]][g - gVec[i]] + vVec[i]);
			}
		}
	}
	return f[wLimit][gLimit];
}

/*六.分组背包问题

*/
