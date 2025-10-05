#include <iostream>
using namespace std;

static const int MOD = 998244353;
static const int MAX_N = (2e5 + 10);

int n;
int nums[MAX_N];

void Solution()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> nums[n];
	}
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