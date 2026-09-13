#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX_N = 2e5 + 10;
const int MAX_M = 3e5 + 10;

const long long INF = 3e15;

// dist, risk, to
vector<tuple<int, int, int>> edges[MAX_N];

// 记录 离 1 节点 的 距离 与 风险
long long dist[MAX_N];
long long risk[MAX_N];

int main()
{
	int n, m;
	cin >> n >> m;

	if (n == 1)
	{
		printf("0 0\n");
		return 0;
	}

	for (int i = 1; i <= m; i++)
	{
		int u, v, d, r;
		cin >> u >> v >> d >> r;
		edges[u].push_back({d, r, v});
	}

	for (int i = 1; i <= n; i++)
	{
		dist[i] = INF;
		risk[i] = INF;
	}

	// Dijkstra

	dist[1] = 0;
	risk[1] = 0;

	// dist, risk, current_node
	priority_queue<tuple<long long, long long, int>, vector<tuple<long long, long long, int>>, greater<>> pq;
	pq.push({0, 0, 1});
	while (pq.size())
	{
		auto [current_d, current_r, current] = pq.top();
		pq.pop();

		// 当前状态过期
		if (current_d != dist[current] || current_r != risk[current])
		{
			continue;
		}

		// 用当前点松弛其他点
		for (auto [d, r, to] : edges[current])
		{
			long long nd = current_d + d;
			long long nr = current_r + r;

			// 松弛
			if (nd < dist[to] || (nd == dist[to] && nr < risk[to]))
			{
				dist[to] = nd;
				risk[to] = nr;
				pq.push({nd, nr, to});
			}
		}
	}

	// 无解
	if (dist[n] == INF || risk[n] == INF)
	{
		printf("-1 -1\n");
		return 0;
	}

	printf("%lld %lld\n", dist[n], risk[n]);
	return 0;
}