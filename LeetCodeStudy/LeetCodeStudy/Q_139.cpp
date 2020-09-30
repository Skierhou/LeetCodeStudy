#include "Q_139.h"
#include <iostream>
#include <unordered_set>

void Q_139::Execute()
{
    string str = "applepenapple";
    vector<string> wordDict{ "apple", "pen" };
    cout << ans_02(str, wordDict);
}

//暴力递归求解，时间复杂度O(n^2)
//思路：每次循环字符串只找最前面列表里存在的子项
bool Q_139::ans_01(string s, vector<string>& wordDict)
{
    int n = s.size();
    bool bres = false;
    for (int i = 0; i <= n; i++)
    {
        if (find(wordDict.begin(), wordDict.end(), s.substr(0, i)) != wordDict.end())
        {
            if (i == n)
                bres = true;
            else
                bres = ans_01(s.substr(i, n - i), wordDict) || bres;
        }
    }
    return bres;
}

//动态规划求解：时间复杂度O(n^2)
//j<i的情况下，dp[i]=dp[j] && check(substr(j,i))
bool Q_139::ans_02(string s, vector<string>& wordDict)
{
    unordered_set<string> hset = unordered_set <string>();
    for (auto s : wordDict)
    {
        hset.insert(s);
    }
    vector<bool> dp(s.size() + 1);
    dp[0] = true;
    for (int i = 1; i <= s.size(); ++i)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] && hset.count(s.substr(j, i-j)))
                dp[i] = true;
        }
    }
    return dp[s.size()];
}
