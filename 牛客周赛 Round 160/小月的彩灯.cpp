#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int x;
		long long k;
		cin >> x >> k;
		k %= 4;
		x <<= k;
		x |= (x >> 4);
		cout << (x & 0xf) << ' ';
		int popcount = 0;
		for (int i = 0; i < 4; i++)
		{
			if ((x >> i) & 1)
			{
				popcount++;
			}
		}
		cout << popcount << endl;
	}
	return 0;
}