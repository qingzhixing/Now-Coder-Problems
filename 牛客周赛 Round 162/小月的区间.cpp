#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 2e5 + 10;

int main()
{
	int n;
	cin >> n;

	vector<int> a(n + 10);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	// 初始化 前缀最大点 和 后缀最小点
	vector<int> prefix_max_id, suffix_min_id;
	int prefix_max_val, suffix_min_val;
	// a[1] 一定是前缀最大点, a[n] 一定是后缀最小点
	prefix_max_id.push_back(1);
	prefix_max_val = a[1];
	suffix_min_id.push_back(n);
	suffix_min_val = a[n];

	// 求前缀最大点
	for (int i = 2; i <= n; i++)
	{
		if (a[i] > prefix_max_val)
		{
			prefix_max_val = a[i];
			prefix_max_id.push_back(i);
		}
	}

	// 求后缀最小点
	for (int i = n - 1; i >= 1; i--)
	{
		if (a[i] < suffix_min_val)
		{
			suffix_min_val = a[i];
			suffix_min_id.push_back(i);
		}
	}
	reverse(suffix_min_id.begin(), suffix_min_id.end());

	long long result = 0;

	// 枚举左端点，二分匹配计算出右端点区间
	for (int l = 1; l <= n; l++)
	{
		// 对前缀最大点和后缀最小点 分别找到第一个不小于 l 的点的下标
		auto prefix_r = lower_bound(prefix_max_id.begin(), prefix_max_id.end(), l);

		// 如果后面没有前缀最大值则直接结束枚举
		if (prefix_r == prefix_max_id.end())
		{
			break;
		}

		auto suffix_r = lower_bound(suffix_min_id.begin(), suffix_min_id.end(), l);

		auto r = max(*prefix_r, *suffix_r);
		result += n - r + 1;
	}

	cout << result << endl;
	return 0;
}