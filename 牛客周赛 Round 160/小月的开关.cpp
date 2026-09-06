#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int a;
		cin >> a;
		cout << (a + 1) % 3 << endl;
	}
	return 0;
}