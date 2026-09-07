#include <iostream>
using namespace std;

const int MAX_N = 3e3 + 10;

int n;

// to 表示 以当前节点为端点的弦的另一端点所在处
int to[MAX_N];

// weight 表示 以当前节点为端点的弦的权重
int weight[MAX_N];

// dp[l][r] 表示 在 [l, r] 区间中所能得到的最大权重
long long dp[MAX_N][MAX_N];

int main()
{
	cin >> n;

	int m = 2 * n;

	for (int i = 1; i <= n; i++)
	{
		int l, r, w;
		cin >> l >> r >> w;
		to[l] = r;
		to[r] = l;
		weight[l] = weight[r] = w;
	}

	// 区间dp
	// 按区间长度枚举
	for (int len = 2; len <= m; len++)
	{
		// 枚举区间左端点
		for (int l = 1; l + len - 1 <= m; l++)
		{
			// 找到一个子区间 [p, r]
			int r = l + len - 1;
			int p = to[r];

			// 不选 [p, r]
			dp[l][r] = dp[l][r - 1];

			// 选 [p, r]
			if (l <= p && p < r)
			{
				dp[l][r] = max(dp[l][r], dp[l][p - 1] + dp[p + 1][r - 1] + weight[r]);
			}
		}
	}

	cout << dp[1][m] << endl;
	return 0;
}