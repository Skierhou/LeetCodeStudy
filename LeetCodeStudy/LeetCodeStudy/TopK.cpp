#include "TopK.h"
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <queue>

void TopK::Execute()
{
    vector<int> vec{ 1,1,2,2,4,2,4,2,4,5 };
    vector<int> res = ans_03(vec, 2);

    for (auto it : res)
    {
        cout << it << endl;
    }
}

vector<int> TopK::ans_01(vector<int>& nums, int k)
{
    unordered_map<int, int> m;
    vector<int> res;

    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]] ++;
    }
    vector<pair<int, int>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), ans_01_cmp);
    auto it = vec.begin();
    while (res.size() < k)
    {
        res.push_back(it->first);
        ++it;
    }
    return res;
}

bool TopK::ans_01_cmp(pair<int, int>& l, pair<int, int>& r)
{
	return l.second > r.second;
}

vector<int> TopK::ans_02(vector<int>& nums, int k)
{
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]] ++;
    }
    //相当于定义vector<pair<int,int>>列表 但是以小顶堆排序
    priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

    for (auto it : m)
    {
        if (pri_que.size() < k)
            pri_que.push(it);
        else
        {
            if (pri_que.top().second < it.second)
            {
                pri_que.pop();
                pri_que.push(it);
            }
        }
    }
    vector<int> res;
    while (pri_que.size() > 0)
    {
        res.push_back(pri_que.top().first);
        pri_que.pop();
    }
    return res;
}

vector<int> TopK::ans_03(vector<int>& nums, int k)
{
    int n = nums.size();
    vector<vector<int>> tong(n + 1, vector<int>());

    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]] ++;
    }
    for (auto it : m)
    {
        tong[it.second].push_back(it.first);
    }
    vector<int> res;
    for (int i = n; i >= 0; i--)
    {
        int len = tong[i].size();
        for (int j = 0; j < len; j++)
        {
            res.push_back(tong[i][j]);
            if (res.size() >= k)
                return res;
        }
    }
    return res;
}
