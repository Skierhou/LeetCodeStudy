#include "Q_399.h"
#include <iostream>
#include <queue>

void Q_399::Execute()
{
	vector<vector<string>> equations;
	equations.push_back({ "a","b" });
	equations.push_back({ "b","c" });
	vector<double> values{2,3};
	vector<vector<string>> queries;
	queries.push_back({ "a","c" });
	queries.push_back({ "c","a" });
    queries.push_back({ "c","b" });
    queries.push_back({ "x","x" });
    vector<double> res = ans_02(equations, values, queries);
	for (auto& a:res)
	{
		cout << a << endl;
	}
}

vector<double> Q_399::ans_01(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
{
	for (int i = 0; i < equations.size(); i++)
	{
		auto e = equations[i];
		graph[e[0]][e[1]] = values[i];
		graph[e[1]][e[0]] = 1.0 / values[i];
	}

	vector<double> res;

	for (auto& s : queries)
	{
		unordered_set<string> vec;
		res.push_back(ans_01_dfs(s[0], s[1], vec));
	}
	return res;
}

double Q_399::ans_01_dfs(string a, string b, unordered_set<string> visited)
{
	if (graph[a].count(b))
		return graph[a][b];

	for (auto& it : graph[a])
	{
		if (visited.count(it.first))
			continue;

		visited.insert(it.first);

		double res = ans_01_dfs(it.first, b, visited);
		if (res > 0.0)
			return res * it.second;
	}
	return -1.0;
}

vector<double> Q_399::ans_02(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
{
    for (int i = 0; i < equations.size(); i++)
    {
        auto e = equations[i];
        graph[e[0]][e[1]] = values[i];
        graph[e[0]][e[0]] = 1.0;
        graph[e[1]][e[0]] = 1.0 / values[i];
        graph[e[1]][e[1]] = 1.0;
    }

    vector<double> res;
    for (auto& query : queries)
    {
        if (!graph.count(query[0]) || !graph.count(query[1]))
        {
            res.push_back(-1.0);
            continue;
        }

        unordered_set<string> visited;
        queue<pair<string, double>> q;

        q.push({ query[0],1.0 });
        bool bfound = false;
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            if (curr.first == query[1])
            {
                res.push_back(curr.second);
                bfound = true;
                break;
            }
            else
            {
                for (auto& neb : graph[curr.first])
                {
                    if (visited.count(neb.first))
                        continue;
                    visited.insert(neb.first);

                    q.push({ neb.first,neb.second * curr.second });
                }
            }
        }
        if (!bfound)
            res.push_back(-1.0);
    }
    return res;
}
