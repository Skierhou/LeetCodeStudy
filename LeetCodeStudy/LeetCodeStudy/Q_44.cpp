#include "Q_44.h"
#include <iostream>

void Q_44::Execute()
{
    string s = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb";
    string p = "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb";
    cout << isMatch(s,0,p,0);
}

bool Q_44::isMatch(string& s, int startS, string& p, int startP)
{
    int ns = s.size();
    int np = p.size();
    if (startS == ns && startP == np) return true;

    int j = startP;
    for (; j < np; ++j)
    {
        char c = p[j];
        if (c == '*')
        { 
            while (j + 1 < np && p[j + 1] == '*')
                ++j;
            break;
        }
        else if (c == '?')
            ++startS;
        else
        {
            if (s[startS] != c)
                return false;
            ++startS;
        }
        if (startS > ns)
            return false;
    }
    if (j == np - 1 || (startS == ns && j == np))
        return true;

    bool res = false;
    for (int i = startS; i < ns; ++i)
    {
        if (j + 1 < np && (s[i] == p[j + 1] || p[j + 1] == '?'))
        {
            res = res || isMatch(s, i + 1, p, j + 2);
        }
    }
    return res;
}
