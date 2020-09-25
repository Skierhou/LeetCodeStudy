#include "Bag01.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


void Bag01::Execute()
{

}

/*
1.�ص㣺ÿ����Ʒֻ��һ����ֻ��Ҫѡ��Ż򲻷�
�Ƶ���ʽ��ǰi����Ʒ������ֵ=max(ǰi-1����Ʒ����ֵ(����i��Ʒ),��i��Ʒ)
--->����f[i][j]���������ѡ���i����Ʒʱ��������ʣ��jʱ������ֵ
������ã�f[i][j] = max(f[i-1][j],f[i-1][j-w[i]]+v[i])
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
2.��һ���ⷨʱ����ΪO(n*V)���ռ�O(n*V)�����Ż���O(n)��ʹ��һά����
�ֽ׶���Ҫ��������⣺��ô����ά����ת����һά����?
������i��1-n��ÿ���ж�f[i][j]ʱ������f[i-1][1...j]���������ÿ���ж�ֻ��Ҫʹ����һ�μ���Ľ��
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

/* ��.��ȫ��������
��Ŀ����N����Ʒ��һ������ΪV�ı�����ÿ����Ʒ�������޼����á���i����Ʒ�ķ�����w[i]����ֵ��v[i]����⽫��Щ��Ʒװ�뱳����ʹ��Щ��Ʒ�ķ����ܺͲ����������������Ҽ�ֵ�ܺ����
*/

/*
1.������Ҫ���ǵ���01����Ϊʲôj�����V...0��Ϊ��ȷ��ÿ�μ���������j-w[i]����������j-w[i]�Ǿ���ѡ�����i�������һ��ѡ��
����ȫ�������⣬����Ҫ����j-w[i]�Ƿ���ѡ�����i�����壬���j��Ҫ�����0...V
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

/* ��.���ر�������
��Ŀ����N����Ʒ��һ������ΪV�ı�������i����Ʒ�����p[i]�����ã�ÿ��������w[i]����ֵ��v[i]��
��⽫��Щ��Ʒװ�뱳����ʹ��Щ��Ʒ�ķ����ܺͲ����������������Ҽ�ֵ�ܺ����
*/

/*
1.������ѡ��ת����01������⣬�ʣ����ת����01������������ƽ����������һ��һά����
ʱ�临�Ӷ�O(N*V*��P[i])
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
2.ʱ�����Ż���ʹ�ö����Ʒ�ʽ�Ż��ظ�����ĵ�����k=1..2..4..2^k��
ʱ�临�Ӷ�O(N*V*��log(P[i]))
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

/*��.��ϱ�������
1.��01��������ȫ�����Լ����ر�����ϳ�һ����Ŀ������1.ֻ��ȡ1�ε���Ʒ��2.��ȡ�����ε���Ʒ��3.��ȡ���������޵���Ʒ
*/

/*
1.���ж�01��������ȫ�����Ļ�ϣ�ֻ��Ҫ��ֳ�����ѭ���Լ�����ѭ�����ɣ�ֻȡ1�ε���Ʒ��������ȡ����Ʒ����
�ټ�����ȡ�������޵���Ʒ���������01������Χ����(�൱�ڶ�漸����Ʒ������)
����p[i] <= 0 ʱ ����������ȡ
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

/*��.��ά���ñ�������
��ά���õı���������ָ������ÿ����Ʒ���������ֲ�ͬ�ķ��ã�ѡ�������Ʒ����ͬʱ���������ִ��ۣ�����ÿ�ִ��۶���һ���ɸ��������ֵ��������������
������ѡ����Ʒ���Եõ����ļ�ֵ���������ִ��۷ֱ�Ϊ����1�ʹ���2����i����Ʒ��������ִ��۷ֱ�Ϊw[i]��g[i]�����ִ��ۿɸ��������ֵ�����ֱ����������ֱ�ΪV��T����Ʒ�ļ�ֵΪv[i]��
*/

/*
1.��ά���ýⷨ��һά���ƣ�����ռ䣬˼·һ��
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

/*��.���鱳������

*/
