#include <iostream>
using namespace std;

void Solution()
{
	int n, k;
	int cnt_0{}, cnt_1{};
	cin >> n >> k;
	while (n--)
	{
		int val;
		cin >> val;
		if (val == 0)
			cnt_0++;
		else
			cnt_1++;
	}

	if (cnt_0 >= k || cnt_1 >= k)
	{
		cout << 0 << endl;
		return;
	}

	if (cnt_1 > (k / 2))
	{
		cout << 0 << endl;
		return;
	}

	cout << 1 << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
		Solution();
	return 0;
}