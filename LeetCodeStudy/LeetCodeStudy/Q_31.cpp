#include "Q_31.h"
#include <algorithm>

void Q_31::Execute()
{
	vector<int> nums{ 1,3,2 };
	nextPermutation(nums);
}

void Q_31::nextPermutation(vector<int>& nums)
{
    int i = nums.size() - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }
    if (i >= 0) {
        int j = nums.size() - 1;
        while (j >= 0 && nums[i] >= nums[j]) {
            j--;
        }
        swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
}
