// LeetCodeStudy.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Q_321.h"
#include <algorithm>
#include <vector>

using namespace std;

void sortEx(vector<int>& vec, int start, int end)
{
    if (start >= end) return;

    int l = start, r = end;
    int record = vec[start];
    while (l < r)
    {
        while (vec[r] >= record && l < r)
            --r;
        if (l < r)
            vec[l] = vec[r];
        while (vec[l] <= record && l < r)
            ++l;
        if (l < r)
            vec[r] = vec[l];
    }
    vec[l] = record;
    sortEx(vec, start, l - 1);
    sortEx(vec, l + 1, end);
}

int main()
{
    IQuestion *q = new Q_321();
    q->Execute();

    return 0;
}