#include "Q_287.h"

void Q_287::Execute()
{

}

int Q_287::ans_01(vector<int>& nums)
{
    //��ָ��ÿ����һ������ָ����������ÿ�μ��㶼���� cur = nums[cur];
    int slow = 0, fast = 0;
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    //���ҵ�slow = fastʱ

    slow = 0;
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}
