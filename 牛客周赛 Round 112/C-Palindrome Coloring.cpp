#include <iostream>
#include <string>
using namespace std;

void Solution()
{
	string str;
	cin >> str;
	int len = str.length();
	for (int pleft = 0, pright = len - 1; pleft < pright; pleft++, pright--)
	{
		if (str[pleft] != str[pright])
		{
			cout << 2 << endl;
			return;
		}
	}
	cout << 1 << endl;
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