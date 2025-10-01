#include <iostream>
#include <vector>
using namespace std;

int n, k;

int main()
{
	cin >> n >> k;

	// n元环 最多拆 n-1 次
	if (k > n - 1)
	{
		cout << -1 << endl;
		return 0;
	}

	/*
	 * x元环 最多拆 x-1 次
	 * 所以 要满足k次操作，必定需要n-k个环，拆 n - (n-k) = k 次
	 */
	int ring_count = n - k;

	/*
	 *	每个环最小大小为 2
	 */
	if (ring_count * 2 > n)
	{
		cout << -1 << endl;
		return 0;
	}

	vector<int> ring_sizes;
	vector<int> result;
	while (ring_count--)
	{
		if (ring_count)
		{
			ring_sizes.push_back(2);
		}
		else
		{
			// 最后一个环里放入所有剩余元素
			ring_sizes.push_back(n - (n - k - 1) * 2);
		}
	}

	int pointer = 1;
	for (auto ring_size : ring_sizes)
	{
		for (auto number = pointer + 1; number <= pointer + ring_size - 1; number++)
		{
			result.push_back(number);
		}
		result.push_back(pointer);
		pointer += ring_size;
	}

	for (auto number : result)
	{
		cout << number << ' ';
	}
	cout << endl;
	return 0;
}