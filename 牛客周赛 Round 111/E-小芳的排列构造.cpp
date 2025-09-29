#include <iostream>
#include <deque>
using namespace std;

long long n, k;

deque<int> result;

deque<int> unused_numbers;

int main()
{
	cin >> n >> k;

	/*
	 * 我们的题目有如下性质:
	 *  n 一定会被计算两次，n-1一定会被计算一次
	 *
	 * 故: 我们可以先不考虑这两个数，到最后构造答案序列时再加上即可
	 */

	k -= n * 2;
	k -= n - 1;

	if (k < 0)
	{
		cout << -1 << endl;
		return 0;
	}

	/*
	 * 从[ n-2 , 1 ] 中凑出k
	 */
	for (int number = n - 2; number >= 1; number--)
	{
		if (k >= number)
		{
			k -= number;

			// 保证 result 从左往右顺序为从小到大
			result.push_front(number);
		}
		else
		{
			unused_numbers.push_back(number);
		}
	}

	// 全部放完了，都没凑出k, k太大了
	if (k > 0)
	{
		cout << -1 << endl;
		return 0;
	}

	// 若 n - 1 存在
	if (n - 1 > 0)
	{
		result.push_back(n - 1);
	}

	for (auto number : unused_numbers)
	{
		result.push_back(number);
	}

	result.push_back(n);

	for (auto number : result)
	{
		cout << number << ' ';
	}
	cout << endl;

	return 0;
}