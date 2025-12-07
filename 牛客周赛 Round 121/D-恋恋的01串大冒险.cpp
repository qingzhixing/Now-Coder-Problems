#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	string str;
	cin >> str;

	int x = 0;		 // 当前正在进行的方案
	int lost = 0;	 // 已经lost了几天
	int pointer = 0; // 正在进行第几天的判断
	while (x <= n)
	{
		// 走到末尾了
		if (pointer > n - 1)
		{
			cout << n << ' ';
			// 下一个方案
			x++;
			continue;
		}

		// 无痛向前
		if (str.at(pointer) == '1')
		{
			pointer++;
			lost = 0;
			continue;
		}
		else
		{
			lost++;
			if (lost >= k)
			{
				// 如果会消失则需要进行转化(到下一种方案)
				// 当前方案到此为止了
				cout << pointer << ' ';
				x++;
				lost = 0;
			}
			pointer++;
		}
	}
	return 0;
}