#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, x, y;
		cin >> n >> m >> x >> y;
		if (n == 1 || m == 1)
		{
			cout << 0 << endl;
			continue;
		}
		bool side_x = false, side_y = false;
		if (x == 1 || x == n)
		{
			side_x = true;
		}
		if (y == 1 || y == m)
		{
			side_y = true;
		}

		if (side_x && side_y)
		{
			cout << 2 * (n + m - 2) << endl;
			continue;
		}
		if (side_x && !side_y)
		{
			cout << 2 * ((n - 1) + (m - 1) + (n - 1)) << endl;
			continue;
		}
		if (!side_x && side_y)
		{
			cout << 2 * ((m - 1) + (n - 1) + (m - 1)) << endl;
			continue;
		}
		if (!side_x && !side_y)
		{
			cout << 4 * ((n - 1) + (m - 1)) << endl;
			continue;
		}
	}
	return 0;
}