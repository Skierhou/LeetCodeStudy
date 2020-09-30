#include "Q_207.h"
#include <iostream>

void Q_207::Execute()
{
	vector<vector<int>> vec;
	vec.push_back({ 1,3 });
	vec.push_back({ 2,4 });
	cout << ans_02(4, vec);
}

#pragma region 解法一

bool Q_207::ans_01(int numCourses, vector<vector<int>>& prerequisites)
{
    unordered_map<int, vector<int>> m;

    int n = prerequisites.size();
    for (int i = 0; i < n; i++)
    {
        if (m.find(prerequisites[i][0]) == m.end())
            m.insert(pair<int, vector<int>>(prerequisites[i][0], { prerequisites[i][1] }));
        else
            m[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    unordered_set<int> readHash, wantHash;
    for (int i = 0; i < n; i++)
    {
        if (!ans_01_read(prerequisites[i][0], readHash, wantHash, m))
            return false;
    }
    return count <= numCourses;
}

bool Q_207::ans_01_read(int colNum, unordered_set<int>& readHash, unordered_set<int>& wantHash, unordered_map<int, vector<int>>& m)
{
    auto it = m.find(colNum);
    if (it == m.end())
    {
        ++count;
        readHash.insert(colNum);
    }
    else
    {
        wantHash.insert(colNum);
        int len = it->second.size();
        for (int j = 0; j < len; j++)
        {
            if (wantHash.find((it->second)[j]) != wantHash.end())
            {
                //失败
                return false;
            }
            if (readHash.find((it->second)[j]) == readHash.end())
            {
                //读
                if (!ans_01_read((it->second)[j], readHash, wantHash, m))
                    return false;
            }
        }
        if (readHash.find(colNum) == readHash.end())
        {
            ++count;
            readHash.insert(colNum);
        }
        auto it = wantHash.find(colNum);
        if (it != wantHash.end())
            wantHash.erase(it);
    }
    return true;
}

#pragma endregion

#pragma region 解法二

bool Q_207::ans_02(int numCourses, vector<vector<int>>& prerequisites)
{
    unordered_map<int, vector<int>> m;
    int n = prerequisites.size();
    for (int i = 0; i < n; i++)
    {
        if (m.find(prerequisites[i][0]) == m.end())
            m.insert(pair<int, vector<int>>(prerequisites[i][0], { prerequisites[i][1] }));
        else
            m[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    int readHash = 0;
    for (int i = 0; i < n; i++)
    {
        if (!ans_02_read(prerequisites[i][0], readHash, 0, m))
            return false;
    }

    return count <= numCourses;
}

bool Q_207::ans_02_read(int colNum, int& readHash, int wantHash, unordered_map<int, vector<int>>& m)
{
    auto it = m.find(colNum);
    if (it == m.end())
    {
        ++count;
        readHash |= (1 << colNum);
    }
    else
    {
        wantHash |= (1 << colNum);
        int len = it->second.size();
        for (int j = 0; j < len; j++)
        {
            if ((wantHash & (1 << (it->second)[j])) != 0)
            {
                //失败
                return false;
            }
            if ((readHash & (1 << (it->second)[j])) == 0)
            {
                //读
                if (!ans_02_read((it->second)[j], readHash, wantHash, m))
                    return false;
            }
        }
        if ((readHash & (1 << colNum)) == 0)
        {
            ++count;
            readHash |= (1 << colNum);
        }
    }
    return true;
}

#pragma endregion
