#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, k;
	string str;
	cin >> n >> k;
	cin >> str;

	int result = 2147483647;

	for (int ch = 'a'; ch <= 'z'; ch++)
	{
		int cnt = 0;
		for (int i = 0, j = 0; i < n; i++)
		{
			if (str[i] == ch)
				cnt++;

			while (cnt >= k)
			{
				result = min(result, i - j + 1);
				if (str[j] == ch)
					cnt--;
				j++;
			}
		}
	}

	if (result == 2147483647)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << result << endl;
	}

	return 0;
}