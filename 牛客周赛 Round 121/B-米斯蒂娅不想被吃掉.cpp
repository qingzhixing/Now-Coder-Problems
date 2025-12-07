#include <iostream>
using namespace std;

int n, x;

void Solution()
{
	cin >> n >> x;
	int yesterday = 0;
	int today = 0;
	int eated = false;
	for (int i = 1; i <= n; i++)
	{
		yesterday = today;
		cin >> today;
		if (eated)
			continue;
		if ((yesterday + today) < x)
		{
			eated = true;
		}
		else
		{
			today -= max(0, (x - yesterday));
		}
	}
	cout << (eated ? "No" : "Yes") << endl;
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