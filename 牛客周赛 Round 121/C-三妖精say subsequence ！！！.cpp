#include <iostream>
#include <string>
using namespace std;

const int MOD = 998244353;

int main()
{
	int n;
	string str;
	cin >> n >> str;

	long long cnt[30]{};
	for (auto ch : str)
	{
		cnt[ch - 'a']++;
	}

	long long result{};

	// 枚举字符排列情况
	for (int c1 = 0; c1 < 26; c1++)
	{
		for (int c2 = 0; c2 < 26; c2++)
		{
			for (int c3 = 0; c3 < 26; c3++)
			{
				if (c1 != c2 && c2 != c3 && c1 != c3)
				{
					result += (cnt[c1] * cnt[c2] * cnt[c3]) % MOD;
					result %= MOD;
				}
			}
		}
	}

	cout << result << endl;

	return 0;
}