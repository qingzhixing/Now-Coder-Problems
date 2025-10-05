#include <iostream>
using namespace std;

void Solution()
{
	int n, max_number;
	cin >> n;
	max_number = n;
	while (n--)
	{
		int number;
		cin >> number;
		max_number = max(max_number, number);
	}

	cout << max_number << endl;
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