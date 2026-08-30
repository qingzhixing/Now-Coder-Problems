#include <iostream>
#include <string>
using namespace std;

const int MAX_N = 2e5 + 10;
// 2^20 < 2e6
const int MAX_M = 2e6;

int a[MAX_N];
bool exist[MAX_M];

int n, b;

int amount;
int cnt[32];

int main()
{
	cin >> n >> b;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		a[i] = std::stoi(s, nullptr, 2);
		exist[a[i]] = true;
	}

	// 对于每一个数字，我们每次更改其每一个 0 为 1 ，若产生的数存在，那么算成功
	for (int i = 1; i <= n; i++)
	{
		for (int digit = 0; digit < b; digit++)
		{
			// 当前位不为 0，跳过
			if ((a[i] >> digit) & 1)
			{
				continue;
			}
			int next = a[i] | (1 << digit);
			if (exist[next])
			{
				cnt[digit]++;
				amount++;
			}
		}
	}

	cout << amount << endl;
	for (int i = b - 1; i >= 0; i--)
	{
		cout << cnt[i] << ' ';
	}
	cout << endl;
	return 0;
}