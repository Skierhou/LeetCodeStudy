#include "Q_973.h"
#include <unordered_map>
#include <algorithm>

void Q_973::Execute()
{
    vector<vector<int>> vec{ {0,1},{1,0} };
    ans_01(vec, 2);
}

vector<vector<int>> Q_973::ans_01(vector<vector<int>>& points, int K)
{
    vector<vector<int>> res;
    int temp = 0;
    int n = points.size();
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < n; ++i)
    {
        int dis = pow(points[i][0], 2) + pow(points[i][1], 2);
        temp = max(dis, temp);
        if (!m.count(dis))
            m[dis] = { i };
        else
            m[dis].push_back(i);
    }
    for (int i = 0; i <= temp; ++i)
    {
        if (m.count(i))
        {
            int len = m[i].size();
            for (int j = 0; j < len; ++j)
            {
                res.push_back(points[m[i][j]]);
                if (--K <= 0)
                    return res;
            }
        }
    }
    return res;
}
