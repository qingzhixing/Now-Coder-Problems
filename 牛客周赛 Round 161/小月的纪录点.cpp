#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int max_val = -1e9 - 10;
	int max_idx = 0;

	int cnt = 0;
	int max_delta = 0;
	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		if (num > max_val)
		{
			max_val = num;
			cnt++;
			max_delta = max(max_delta, i - max_idx);
			max_idx = i;
		}
	}

	if (cnt < 2)
	{
		max_delta = 0;
	}

	printf("%d %d\n", cnt, max_delta);
	return 0;
}