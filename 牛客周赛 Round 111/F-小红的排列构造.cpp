#include <iostream>
using namespace std;

int n, k;

int main()
{
	cin >> n >> k;

	if (k < n / 2)
	{
		cout << -1 << endl;
	}
	else
	{
		for (int i = n; i >= 1; i--)
		{
			cout << i << ' ';
		}
	}
	// TODO: 骗分
	return 0;
}