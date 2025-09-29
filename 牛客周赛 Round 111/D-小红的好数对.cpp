#include <iostream>
#include <cstring>
using namespace std;

static const int MAX_N = (2e5 + 10);

int n;

long long answer;

/*
 * delta[i] 表示 第i个数字 (奇数位和 - 偶数位和) % 11
 */
int delta[MAX_N];

/*
 * odd[i] 表示 第i个数字 的长度是否为 奇数
 */
bool odd[MAX_N];

/*
 * counter[i] 表示 满足 delta[j] % 11 == i 时，j 的个数
 */
int counter[20];

/*
 * 用于处理数字，返回[ (其奇数位之和-偶数位之和), 数位是否为奇数 ]
 */
pair<int, bool> handle(int number)
{
	int current_digit = 0;
	int current_delta = 0;
	while (number)
	{
		current_digit++;
		int digit = number % 10;
		if (current_digit % 2)
		{
			current_delta -= digit;
		}
		else
		{
			current_delta += digit;
		}
		number /= 10;
	}

	while (current_delta < 0)
		current_delta += 11;

	return {current_delta % 11, current_digit % 2 == 1};
}

int main()
{
	cin >> n;
	for (int index = 1; index <= n; index++)
	{
		int number;
		cin >> number;
		auto [current_delta, current_odd] = handle(number);
		delta[index] = current_delta;
		odd[index] = current_odd;
	}

	// 从左往右顺序遍历
	for (int index = 1; index <= n; index++)
	{
		if (odd[index])
		{
			answer += counter[delta[index]];
		}
		else
		{
			answer += counter[(11 - delta[index]) % 11];
		}

		/*
		 * counter在遍历完成当前数字之后更新，保证每次匹配的数字只可能在当前数字的前面
		 * 	这样保证数对 (a_i, a_j) 中, i和j 相对大小关系唯一确定: (i < j)
		 */
		counter[delta[index]]++;
	}

	// 从右往左逆序遍历
	memset(counter, 0, sizeof(counter));
	for (int index = n; index >= 1; index--)
	{
		if (odd[index])
		{
			answer += counter[delta[index]];
		}
		else
		{
			answer += counter[(11 - delta[index]) % 11];
		}

		/*
		 * counter在遍历完成当前数字之后更新，保证每次匹配的数字只可能在当前数字的后面
		 * 	这样保证数对 (a_i, a_j) 中, i和j 相对大小关系唯一确定: (i > j)
		 */
		counter[delta[index]]++;
	}

	cout << answer << endl;
	return 0;
}