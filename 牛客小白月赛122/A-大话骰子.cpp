#include <iostream>
using namespace std;

void Solution()
{
	int a[10], b[10];
	for (int i = 1; i <= 6; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= 6; i++)
	{
		cin >> b[i];
	}

	int x, y;
	cin >> x >> y;
	int result = 0;
	for (int i = 1; i <= 6; i++)
	{
		if (a[i] == y)
			result++;
		if (b[i] == y)
			result++;
	}

	cout << ((result < x) ? "win" : "lose") << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
		Solution();

	return 0;
}