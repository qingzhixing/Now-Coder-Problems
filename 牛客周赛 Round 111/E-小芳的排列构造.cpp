#include <iostream>
using namespace std;

int n, k;

int main()
{
	cin >> n >> k;
	// 骗分: k比n顺序排列加起来还要大那么则不可能有想要的排列
	if (k > (n * (n + 1) / 2 + n))
	{
		cout << -1 << endl;
	}
	return 0;
}