#include <iostream>
using namespace std;

int n;
long long result;

int main()
{
	cin >> n;
	char c, last_c;
	cin >> c;
	last_c = c;

	while (n--)
	{
		cin >> c;
		result *= 2;
		if (c == last_c)
		{
			result += 2;
		}
	}

	cout << result << endl;
	return 0;
}