#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

static const int MAX_N = (4e5 + 10);
int n;
long long nums[MAX_N];
int bit_count[100];

void handle_bits(long long value)
{
	int current_bit = 1;
	while (value)
	{
		if (value & 1)
			bit_count[current_bit]++;
		value >>= 1;
		current_bit++;
	}
}

void Solution()
{
	memset(nums, 0, sizeof(nums));
	memset(bit_count, 0, sizeof(bit_count));

	cin >> n;
	for (int index = 1; index <= 2 * n; index++)
	{
		cin >> nums[index];
	}

	sort(nums + 1, nums + 1 + n);

	long long harmony = nums[n + 1];
	for (int index = n + 1; index <= 2 * n; index++)
	{
		harmony &= nums[index];
	}

	// 跟bit统计对比
	long long bit_value;
	for (int bit_index = 1; bit_index <= sizeof(long long) * 8; bit_index++)
	{
		bit_value = 1 << bit_index;
		if (bit_count[bit_index] >= n)
			harmony = max(harmony, bit_value);
	}

	cout << harmony << endl;
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