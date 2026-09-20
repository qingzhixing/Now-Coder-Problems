#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX_N = 2e5 + 10;

int n;
int a[MAX_N];

void Solution()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	sort(a + 1, a + 1 + n);

	int x = a[1];
	int k = 0;
	for (int i = 2; i <= n; i++)
	{
		x = max(x + 1, a[i]);
		k = max(1.0 * k, ceil((x - a[i]) / 2.0));
	}

	cout << k << endl;
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