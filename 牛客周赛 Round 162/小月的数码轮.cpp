#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAX_N = 1e5 + 10;
const int MAX_M = 1e9;

long long divide(const vector<int> &divisor, long long dividend)
{
	long long remainder = 0;
	for (int digit = 0, len = divisor.size(); digit < len; digit++)
	{
		remainder = remainder * 10 + divisor[digit];
		remainder %= dividend;
	}
	return remainder;
}

int main()
{
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<int> num(n);
	for (auto i = 0; i < n; i++)
	{
		num[i] = s[i] - '0';
	}

	int result = 0;
	for (int x = 0; x <= 9; x++)
	{
		auto remainder = divide(num, m);
		if (remainder == 0)
		{
			result++;
		}
		for (int i = 0; i < n; i++)
		{
			num[i] = (num[i] + 1) % 10;
		}
	}
	cout << result << endl;
	return 0;
}