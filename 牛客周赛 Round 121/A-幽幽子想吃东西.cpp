#include <iostream>
using namespace std;

int main()
{
	int a, b, c, n;
	cin >> a >> b >> c >> n;
	cout << (a * n - (n <= b ? c : 0)) << endl;
	return 0;
}