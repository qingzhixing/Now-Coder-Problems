#include <iostream>
#include <algorithm>
using namespace std;

#error TODO: Wrong Answer

const int MAX_N = 2e5;

int n, t;
pair<int, int> line[MAX_N];

// 查找第一个 二元组 >= (x, k) 的位置（左边界）
int lower_bound(int x, int k, int l, int r)
{
	if (l >= r)
	{
		return l; // 左闭右开区间 [l, r)
	}
	int mid = l + ((r - l) >> 1);

	// 如果 line[mid] < (x, k)，向右走
	if (line[mid].first < x ||
		(line[mid].first == x && line[mid].second < k))
	{
		return lower_bound(x, k, mid + 1, r);
	}
	else
	{
		return lower_bound(x, k, l, mid);
	}
}

// 查找第一个 二元组 > (x, k) 的位置（右边界）
int upper_bound(int x, int k, int l, int r)
{
	if (l >= r)
	{
		return l;
	}
	int mid = l + ((r - l) >> 1);

	// 如果 line[mid] <= (x, k)，向右走
	if (line[mid].first < x ||
		(line[mid].first == x && line[mid].second <= k))
	{
		return upper_bound(x, k, mid + 1, r);
	}
	else
	{
		return upper_bound(x, k, l, mid);
	}
}

int main()
{
	cin >> n >> t;
	for (int i = 1; i <= n; i++)
	{
		int l, r;
		cin >> l >> r;
		line[i] = {l, r};
	}

	// 按左端点从小到大排序
	sort(line + 1, line + 1 + n);

	long long result = 0;
	for (int i = 1; i <= n; i++)
	{
		auto [left, right] = line[i];
		auto target_left = right;
		auto target_right = left + t;
		auto l_idx = lower_bound(target_left, target_right, 1, n);
		auto r_idx = upper_bound(target_left, target_right, 1, n);
		// 没找到
		if (line[l_idx].first != target_left || line[l_idx].second != target_right)
		{
			continue;
		}
		result += r_idx - l_idx;
	}

	cout << result << endl;
	return 0;
}