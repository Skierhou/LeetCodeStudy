#include "NQueen.h"

void NQueen::Execute()
{
    ans_01(6);
}

#pragma region 解法一：相当于暴力回溯
vector<vector<string>> NQueen::ans_01(int n)
{
    vector<vector<string>> res;
    for (int i = 0; i < n; i++)
    {
        vector<vector<char>> vec(n, vector<char>(n));
        for (int j = 0; j < n; j++)
            vec[0][j] = '.';
        vec[0][i] = 'Q';
        ans_01_backtrack(vec, 1 << i, 1, n, res);
    }
    return res;
}
void NQueen::ans_01_backtrack(vector<vector<char>> vec, int hash, int layer, int n, vector<vector<string>>& res)
{
    if (layer == n)
    {
        vector<string> temp(n);
        for (int i = 0; i < n; i++)
        {
            temp[i].assign(vec[i].begin(), vec[i].end());
        }
        res.push_back(temp);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if ((hash & (1 << i)) == 0 && ans_01_check(vec, i, layer, n))
        {
            int temp = hash;
            temp |= (1 << i);
            for (int j = 0; j < n; j++)
                vec[layer][j] = '.';
            vec[layer][i] = 'Q';
            ans_01_backtrack(vec, temp, layer + 1, n, res);
        }
    }
}

bool NQueen::ans_01_check(vector<vector<char>> vec, int i, int layer, int n)
{
    int l = i - 1, r = layer - 1;
    while (l >= 0 && r >= 0)
    {
        if (vec[r][l] == 'Q')
        {
            return false;
        }
        --r; --l;
    }
    l = i + 1;
    r = layer - 1;
    while (l < n && r >= 0)
    {
        if (vec[r][l] == 'Q')
            return false;
        ++l; --r;
    }
    return true;
}
#pragma endregion

#pragma region 解法二：优化解法，空间优化
vector<vector<string>> NQueen::ans_02(int n)
{
    vector<vector<string>> res;
    vector<int> vec;
    ans_02_backtrack(0, 0, 0, 0, n, vec, res);
    return res;
}

void NQueen::ans_02_backtrack(int col, int bevel1, int bevel2, int layer, int n,vector<int>& vec,vector<vector<string>>& res)
{
    if (layer == n)
    {
        res.push_back(ans_02_generated(vec));
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if ((col & (1 << i)) == 0 && (bevel1 & (1 << i)) == 0 && (bevel2 & (1 << i)) == 0)
        {
            int temp = col | (1 << i);
            int temp1 = (bevel1 | (1 << i)) << 1;
            int temp2 = (bevel2 | (1 << i)) >> 1;
            vec.push_back(i);
            ans_02_backtrack(temp, temp1, temp2, layer + 1, n, vec, res);
            vec.erase(vec.begin() + vec.size() - 1);
        }
    }
}

vector<string> NQueen::ans_02_generated(vector<int> vec)
{
    vector<string> res;
    for (int i = 0; i < vec.size(); i++)
    {
        string str;
        for (int j = 0; j < vec.size(); j++)
        {
            if (vec[i] == j)
                str += 'Q';
            else
                str += '.';
        }
        res.push_back(str);
    }
    return res;
}
#pragma endregion
