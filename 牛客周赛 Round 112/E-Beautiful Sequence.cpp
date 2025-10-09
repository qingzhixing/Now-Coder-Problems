#include <iostream>
#include <vector>
using namespace std;

static const long long MOD = 998244353LL;
static const int MAX_N = (2e5 + 10);

long long quick_pow(long long num1, long long num2, long long mod)
{
	num1 %= mod;
	long long result = 1;

	while (num2)
	{
		if (num2 & 1)
			result = (result * num1) % mod;
		num2 >>= 1;
		num1 = (num1 * num1) % mod;
	}

	return result % mod;
}

void Solution()
{
	int n;
	cin >> n;

	vector<int> nums(n + 10, 0);
	/*
	 * count[i]用于统计值为i的数字有多少个
	 */
	vector<int> count(n + 10, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> nums[i];
		count[nums[i]]++;
	}

	// 合法美丽序列
	long long valid_answer = 0;

	// 枚举gcd的值
	for (int gcd = 1; gcd <= n; gcd++)
	{
		// 值为gcd的元素个数
		int gcd_count = count[gcd];
		// 值为gcd倍数(值!=gcd)的元素的个数
		int multiple_count = 0;

		// 枚举gcd的倍数
		for (int multiple = gcd * 2; multiple <= n; multiple += gcd)
		{
			multiple_count += count[multiple];
		}

		// 对于当前gcd，选择其本身和其倍数，能组成 (2^gcd_count - 1) * (2^multiple_count)个不同的序列
		// (2^gcd_count - 1)是因为对于gcd，我们只能保留其非空子集
		valid_answer += ((quick_pow(2, gcd_count, MOD) - 1) % MOD) * (quick_pow(2, multiple_count, MOD) % MOD);
		valid_answer %= MOD;

		// printf("gcd: %lld, gcd_count: %lld, multiple_count: %lld, delta_ans: %lld\n", gcd, gcd_count, multiple_count, (((1LL << gcd_count) % MOD - 1) * ((1LL << multiple_count) % MOD)) % MOD);
	}

	// 答案是 总非空(题目要求非空)子序列个数-合法美丽数列个数
	long long invalid_answer = ((quick_pow(2, n, MOD) - 1 - valid_answer) % MOD) + MOD;
	invalid_answer %= MOD;
	cout << invalid_answer << endl;
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