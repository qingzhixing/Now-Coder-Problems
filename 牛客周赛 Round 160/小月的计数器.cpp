#include <iostream>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	long long result = 0;
	long long current_op = 1;
	while (n)
	{
		if (n & 1)
		{
			result += current_op;
		}
		current_op = current_op * 2 + 1;
		n >>= 1;
	}
	cout << result << endl;
	return 0;
}