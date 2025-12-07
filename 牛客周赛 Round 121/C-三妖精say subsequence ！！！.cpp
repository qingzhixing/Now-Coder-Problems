#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

const int MOD = 998244353;

long long A(int bottom, int top)
{
	if (top > bottom)
		return 0;
	long long sum = 1;
	for (int i = 0; i < top; i++)
	{
		sum = sum * (bottom - i) % MOD;
	}
	return sum;
}

long long C(int bottom, int top)
{
	if (top > bottom)
		return 0;
	return (A(bottom, top) % MOD) / (A(top, top) % MOD);
}

int main()
{
	int n;
	string str;
	cin >> n >> str;

	int different_char_count = 0;
	int checked[30] = {};

	for (auto ch : str)
	{
		if (!checked[ch - 'a'])
			different_char_count++;
		checked[ch - 'a']++;
	}
	long long result = (1LL * C(different_char_count, 3) * A(3, 3)) % MOD;
	for (int i = 0; i < 26; i++)
	{
		if (checked[i])
			result = result * checked[i] % MOD;
	}
	cout << result % MOD << endl;
	return 0;
}