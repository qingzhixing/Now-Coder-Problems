#include <iostream>
using namespace std;

static const int MAX_N = 1e5 + 10;

void Solution()
{
	int n, m;
	cin >> n >> m;
	int positive{}, negative{}, zero{};
	while (n--)
	{
		int val;
		cin >> val;
		if (val > 0)
			positive++;
		else if (val == 0)
			zero++;
		else
			negative++;
	}

	// printf("+: %d, -: %d, 0: %d\n", positive, negative, zero);

	if (positive == m)
	{
		// puts("equal");
		cout << 0 << endl;
		return;
	}
	if (positive > m)
	{
		if (negative || zero)
		{
			// puts("positive-");
			cout << positive - m << endl;
		}
		else
		{
			// puts("positive can't transform");
			cout << -1 << endl;
		}
		return;
	}

	if (positive < m)
	{
		int delta = m - positive;
		if (negative > delta)
		{
			// puts("positive+");
			cout << delta << endl;
		}
		else
		{
			// puts("negative less");
			cout << -1 << endl;
		}
		return;
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
		Solution();
	return 0;
}