#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long x;
		cin >> x;
		unsigned long long r = sqrt(x);
		if (r * r > x)
		{
			r--;
		}
		printf("%llu %llu %llu\n", r, x - r * r, (r + 1) * (r + 1) - x);
	}
	return 0;
}