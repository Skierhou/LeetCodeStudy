#include "Q_1002.h"
#include <algorithm>
#include <iostream>

void Q_1002::Execute()
{
    vector<string> vec{ "bella","label","roller" };
    vector<string> res = ans_01(vec);
    for (auto& r :res)
    {
        cout << r << endl;
    }
}

vector<string> Q_1002::ans_01(vector<string>& A)
{
    int n = A.size();
    if (n == 0) return {};

    vector<string> res;
    //26代表对应字母
    vector<int> ans(26, 0);
    for (int i = 0; i < A[0].size(); ++i)
    {
        ++ans[A[0][i] - 'a'];
    }
    for (int i = 1; i < n; ++i)
    {
        //每次获取并于上一次取最小
        vector<int> temp(26, 0);
        for (int j = 0; j < A[i].size(); ++j)
        {
            ++temp[A[i][j] - 'a'];
        }
        for (int k = 0; k < ans.size(); ++k)
        {
            ans[k] = min(ans[k], temp[k]);
        }
    }
    for (int i = 0; i < ans.size(); ++i)
    {
        if (ans[i] > 0)
        {
            for (int j = 0; j < ans[i]; j++)
            {
                string s{ (char)(i + 'a') };
                res.push_back(s);
            }
        }
    }

    return res;
}
