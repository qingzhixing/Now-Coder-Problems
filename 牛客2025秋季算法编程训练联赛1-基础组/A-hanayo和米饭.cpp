#include <iostream>
using namespace std;

static const int MAX_N = 1e5 + 10;

int n;
bool exist[MAX_N];

int main()
{
	cin >> n;
	for (int i = 1; i <= n - 1; i++)
	{
		int num;
		cin >> num;
		exist[num] = true;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!exist[i])
		{
			cout << i << endl;
			break;
		}
	}
	return 0;
}