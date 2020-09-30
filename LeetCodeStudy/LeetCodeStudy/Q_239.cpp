#include "Q_239.h"
#include <iostream>

void Q_239::Execute()
{
    vector<int> nums{ 1,3,-1,-3,5,3,6,7 };
    vector<int> res = ans_02(nums, 3);
    for (auto it : res)
    {
        cout << it << endl;
    }
}

vector<int> Q_239::ans_01(vector<int>& nums, int k)
{
    vector<int> res;
    int n = nums.size();
    for (int i = 0; i < n-k; i++)
    {
        int tMax = INT_MIN;
        for (int j = i; j < i + k; j++)
        {
            tMax = max(tMax,nums[j]);
        }
        res.push_back(tMax);
    }
    return res;
}

vector<int> Q_239::ans_02(vector<int>& nums, int k)
{
    int n = nums.size();
    if (n * k == 0) return {};
    //双端队列存下标，front()放最大，back()放最小
    deque<int> window;
    for (int i = 0; i < k; i++)
    {
        while (!window.empty() && nums[window.back()] <= nums[i])
        {
            window.pop_back();
        }
        window.push_back(i);
    }
    vector<int> res{ nums[window.front()] };
    for (int i = k; i < n; i++)
    {
        if (!window.empty() && window.front() <= i - k)
        {
            window.pop_front();
        }
        while (!window.empty() && nums[window.back()] <= nums[i])
        {
            window.pop_back();
        }
        window.push_back(i);
        res.push_back(nums[window.front()]);
    }
    return res;
}
