#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int MAX_N = 50;
const int MOD = 1e9 + 7;

int n, k, x;
int a[MAX_N];

// 枚举区间 [start, end] 的所有子集选和不选，计算异或和并加入 vector
void generate_subsets(int start, int end,
					  int selected_count, int xor_sum,
					  vector<pair<int, int>> &states)
{
	// 枚举完毕
	if (start > end)
	{
		states.emplace_back(selected_count, xor_sum);
		return;
	}

	// 不选 a[start]
	generate_subsets(start + 1, end, selected_count, xor_sum, states);

	// 选 a[start]
	generate_subsets(start + 1, end, selected_count + 1, xor_sum ^ a[start], states);
};

int main()
{
	cin >> n >> k >> x;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	// selected_cnt, xor_sum
	vector<pair<int, int>>
		left_result, right_result;

	// 折半搜索
	int mid = n >> 1;
	// left
	generate_subsets(1, mid, 0, 0, left_result);
	// right
	generate_subsets(mid + 1, n, 0, 0, right_result);

	// 对于右侧部分用map统计个数，待会用于查询
	// {selected_cnt, xor_sum} -> cnt
	map<pair<int, int>, int> right_freq;

	for (auto &item : right_result)
	{
		right_freq[item]++;
	}

	int ans = 0;
	// 对于每个可重复的左侧产生的值，查询其右侧的值，产生的方案数为 1 * cnt
	for (auto &[selected_cnt, xor_sum] : left_result)
	{
		auto needed_selected_cnt = k - selected_cnt;
		auto needed_xor_sum = x ^ xor_sum;

		auto find_result = right_freq.find({needed_selected_cnt, needed_xor_sum});
		if (find_result != right_freq.end())
		{
			auto &[_, cnt] = *find_result;
			ans = (ans + cnt) % MOD;
		}
	}

	cout << ans << endl;

	return 0;
}