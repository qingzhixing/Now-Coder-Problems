#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, k;
	string str;
	cin >> n >> k;
	cin >> str;

	int result = -1;

	for (int bit = '0'; bit <= '1'; bit++)
	{
		int cnt = 0;
		for (int i = 0, j = 0; i < n; i++)
		{
			if (str[i] == bit)
				cnt++;

			while (cnt > k)
			{
				if (str[j] == bit)
					cnt--;
				j++;
			}

			result = max(result, i - j + 1);
			// printf("result: %d, cnt: %d\n", result, cnt);
		}
	}

	cout << result << endl;

	return 0;
}