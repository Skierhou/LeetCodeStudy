#include "Q_287.h"

void Q_287::Execute()
{

}

int Q_287::ans_01(vector<int>& nums)
{
    //慢指针每次走一步，快指针走两步，每次计算都是以 cur = nums[cur];
    int slow = 0, fast = 0;
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    //当找到slow = fast时

    slow = 0;
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}
