#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;

void Solution()
{
	cin >> n;

	vector<long long> nums(2 * n + 10);

	for (int index = 1; index <= 2 * n; index++)
	{
		cin >> nums[index];
	}

	/*
	 * 试填法贪心: 从高位往低位试填
	 */
	long long answer = 0;
	vector<bool> enabled(2 * n + 10, true);
	for (int bit = 45; bit >= 0; bit--)
	{
		vector<int> enabled_index{};
		for (int index = 1; index <= 2 * n; index++)
		{
			// 当前数字在先前已被排除
			if (!enabled[index])
			{
				continue;
			}

			// 当前位可选择，则尝试选择
			if ((nums[index] >> bit) & 1)
			{
				enabled_index.push_back(index);
			}
		}

		vector<bool> next_enabled(2 * n + 10);
		// 如果试填结果满足要求则可填
		if (enabled_index.size() >= n)
		{
			answer |= 1LL << bit;
			for (auto index : enabled_index)
			{
				next_enabled[index] = true;
			}
			enabled = next_enabled;
		}
	}

	cout << answer << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Solution();
	}
	return 0;
}