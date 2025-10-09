#include <iostream>
#include <vector>
#include <string>
using namespace std;

static const int MOD = 1e9 + 7;

/*
 * first: 最小的前缀和
 * secound: 最后一位前缀和
 */
typedef pair<int, int> BracketData;

void Solution()
{
	int n;
	cin >> n;

	vector<BracketData> bracket_data_array(n);
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		// 处理当前字符串数据
		int pre_sum = 0;
		int min_pre_sum = 1e8;
		for (auto ch : str)
		{
			if (ch == '(')
			{
				pre_sum++;
			}
			else
			{
				pre_sum--;
			}
			min_pre_sum = min(min_pre_sum, pre_sum);
		}

		bracket_data_array[i] = make_pair(min_pre_sum, pre_sum);
	}

	/*
	 *	我们使用状态压缩来做这道题，用一个整数记录字符串启用状态:
	 *		当第i位为1表示启用，反之不启用
	 */

	// 我们预处理出每种情况的前缀和最后位，放在last_pre数组中
	vector<int> last_pre(1 << n);
	for (int state = 0; state < (1 << n); state++)
	{
		for (int bit = 0; bit < n; bit++)
		{
			if ((state >> bit) & 1)
			{
				last_pre[state] += bracket_data_array[bit].second;
			}
		}
	}

	// 不可能有合法排列
	if (last_pre.back() != 0)
	{
		cout << 0 << endl;
		return;
	}

	/*
	 * dp[i] 表示第i种状态有的排列方式数
	 */
	vector<int> dp(1 << n);
	dp[0] = 1;
	for (int state = 0; state < (1 << n); state++)
	{
		for (int bit = 0; bit < n; bit++)
		{
			// 是从之前状态转移过来的
			if ((state >> bit) & 1)
			{
				int last_state = state ^ (1 << bit);
				// 当前位置可以从目标上一个状态转移过来(放在上一种情况的后面)
				if (last_pre[last_state] + bracket_data_array[bit].first >= 0)
				{
					dp[state] += dp[last_state];
					dp[state] %= MOD;
				}
			}
		}
	}

	cout << dp.back() << endl;
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