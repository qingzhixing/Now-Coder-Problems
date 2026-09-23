#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX_N = 2e5 + 10;

int n;
string color;

// 邻接表存图
vector<int> nxt[MAX_N];

// 以 i 为节点的子树中 被标记的节点的数量
int cnt[MAX_N];

// 当前点上是否在必删边上
bool edge_mark[MAX_N];

// 当前点是否要删除
bool delete_mark[MAX_N];

// 以 root 为根查询其cnt
int query_cnt(int from, int root)
{
	cnt[root] = edge_mark[root];

	// 枚举所有边并遍历
	for (auto nxt_id : nxt[root])
	{
		// 不能往回走
		if (nxt_id == from)
		{
			continue;
		}
		cnt[root] += query_cnt(root, nxt_id);
	}

	return cnt[root];
}

int main()
{
	cin >> n >> color;
	color = " " + color; // 1 - indexed

	// 读入边
	for (int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		nxt[u].push_back(v);
		nxt[v].push_back(u);

		// 判断是否需要标记
		if (color[u] != color[v])
		{
			edge_mark[u] = true;
			edge_mark[v] = true;
		}
	}

	int root = -1;
	// 找到一个叶子节点当做 root
	for (int i = 1; i <= n; i++)
	{
		if (nxt[i].size() == 1)
		{
			root = i;
			break;
		}
	}

	if (root == -1)
	{
		root = 1;
	}

	// 用这一点初始化 cnt
	auto root_cnt = query_cnt(-1, root);

	// 初始化要删除的节点
	for (int i = 1; i <= n; i++)
	{
		if (!edge_mark[i] && (cnt[i] == 0 || cnt[i] == root_cnt))
		{
			delete_mark[i] = false;
		}
		else
		{
			delete_mark[i] = true;
		}
	}

	// 删除 delete_mark[i] = 1 的连通块
	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!delete_mark[i])
		{
			continue;
		}

		// 判断这个点是否在连通块的边缘，如果在，那么我们可以不删除这个点
		int nxt_cnt = 0;
		for (auto nxt_id : nxt[i])
		{
			if (delete_mark[nxt_id])
			{
				nxt_cnt++;
			}
		}

		// 不在边缘则删除
		if (nxt_cnt > 1)
		{
			result++;
		}
	}

	// 至少要删除一个节点
	if (result == 0)
	{
		result++;
	}

	cout << result << endl;

	return 0;
}