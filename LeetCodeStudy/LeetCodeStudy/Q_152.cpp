#include "Q_152.h"
#include <algorithm>
#include <iostream>

void Q_152::Execute()
{
    vector<int> vec{-2,1,-1};
    cout << ans_01(vec);
}

int Q_152::ans_01(vector<int>& nums)
{
    if (nums.size() <= 0) return 0;

    int tMax = INT_MIN;
    for (int i = 0; i < nums.size(); ++i)
    {
        int temp = nums[i];
        tMax = max(tMax, temp);
        for (int j = i + 1; j < nums.size(); ++j)
        {
            temp *= nums[j];
            tMax = max(tMax, temp);
        }
    }
    return tMax;
}

int Q_152::ans_02(vector<int>& nums)
{
    int tMax = nums[0], tMin = nums[0], res = nums[0];
    for (size_t i = 0; i < nums.size(); i++)
    {
        int ma = tMax, mi = tMin;
        tMax = max(nums[i], max(ma * nums[i], mi * nums[i]));
        tMin = min(nums[i], min(ma * nums[i], mi * nums[i]));
        res = max(tMax,res);
    }
    return res;
}
