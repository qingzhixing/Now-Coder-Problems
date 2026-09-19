#include <iostream>
using namespace std;

void Solution()
{
	int a, b;
	cin >> a >> b;
	int mod = ((a - b) % 6 + 6) % 6;
	if (mod == 0 || mod == 1 || mod == 5)
	{
		cout << "Bob" << endl;
	}
	else
	{
		cout << "Alice" << endl;
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